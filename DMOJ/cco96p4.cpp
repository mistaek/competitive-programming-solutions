/*
cco96p4
ac
*/

#include <cstdio>
#include <string> 
#include <iostream>

using namespace std; 
int ydir[8] = {0, 1, 0, -1, 1, -1, 1, -1}, xdir[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int m, n; char grid[50][50];

bool searche(int x, int y, string word, int ind, int dir){
    if(ind >= (int) word.length()){  return true; }
    
    if(x >= m || x < 0 || y >= n || y < 0) return false; 
    if(word[ind] != grid[x][y]) return false; 
    
    if(dir == -1){
        bool ans = false; 
        for(int i = 0; i < 8; i++){
            if(searche(x + xdir[i], y + ydir[i], word, ind+1, i)){ ans= true;}

        }
        return ans; 
    }
    else{
        if(searche(x + xdir[dir], y + ydir[dir], word, ind+1, dir)){ return true;} 
        
    }
    return false; 
}

int main(){
    int tc; scanf("%d", &tc); 
    while(tc--){
        scanf("%d %d", &m, &n);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf(" %1c", &grid[i][j]);
                grid[i][j] = tolower(grid[i][j]);
            }
        }
        int tc2; scanf("%d", &tc2); 
        while(tc2--){
            string word; cin >> word; 
            for(int i = 0; i < word.length(); i++) word[i] = tolower(word[i]);
            bool ansfound = false; 
            for(int i = 0; i < m; i++){
                for(int j = 0; j < n; j++){
                    if(searche(i, j, word, 0, -1)){printf("%d %d\n", i + 1, j + 1); ansfound = true; }
                    if(ansfound) break;  
                }
                if(ansfound) break; 
            }
            if(!ansfound) printf("something went wrong, not found!\n");
        }
        if(tc) printf("\n");

    }
    return 0;
}