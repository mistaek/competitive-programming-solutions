/*
ccc06s4
wip
*/

#include <cstdio>
#include <vector>

using namespace std; 

int main(){
    int dx, grid[101][101]; 
    while(scanf("%d", &dx), dx){
        printf("%d\n", dx);
        for(int i = 1; i <= dx; i++){
            for(int j = 1; j <= dx; j++){
                scanf("%d", &grid[i][j]);
            }
        }
        vector<int> ident; int aident = -1; // there can only be in theory one identity element 
        for(int i = 1; i <= dx; i++){
            for(int j = 1; j <= dx; j++){
                if(grid[i][j] != j) break; 
                if(j == dx) ident.push_back(i);
            }
        }
        if(ident.empty()){ printf("no\n"); continue;}
        for(int j :ident){
            for(int i = 1; i <= dx; i++){
                if(grid[i][j] != i) break; 
                if(i == dx) aident = j;
            }
        }
        if(aident == -1){printf("no\n"); continue;}
        bool check;
        for(int i =1; i <=dx; i++){
            bool check = false; 
            for(int j = 1; j <= dx; j++){
                if(grid[i][j] == aident && grid[j][i] == aident)check = true;  
            }
            if(!check){ printf("no\n"); break;}
        }
        if(!check) continue;

        for(int i = 1; i <= dx; i++){
            check = true;
            for(int j = 1; j <= dx; j++){
                for(int k = 1; k <= dx; k++){
                    if(grid[i][grid[j][k]] != grid[grid[i][j]][k]) check = false; 
                    if(!check) break; 
                }
                if(!check) break; 
            }
            if(!check) break;
        } 
        if(!check){ printf("no\n"); continue; }
        printf("yes\n");

    }
    return 0;   
}