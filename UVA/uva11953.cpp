/*
uva 11953
ray
AC
*/

#include <cstdio>


//thsi all depends on what overlapping/touching is
//simple!
int dirx[] = {1, -1, 0, 0}; 
int x; 
int diry[] = {0, 0, 1, -1}; 
char grid[101][101]; 
int ans = 0; 

void dfs(int i, int j){
    if( i < 0 || j < 0 || i >= x || j >= x) return; 
    if(grid[i][j] == '.')return; 
    grid[i][j] = '.';
    for(int d = 0; d < 4; d++) dfs(i+dirx[d], j + diry[d]); 
}

int main(){
    int TC; scanf("%d", &TC); 
    for(int tc = 1; tc <= TC; tc++){
        
        scanf("%d", &x); 
        for(int i = 0; i < x; i++){
            for(int j = 0; j < x; j++){
                scanf(" %c", &grid[i][j]);
            }
        }

        for(int i = 0; i < x; i++){
            for(int j = 0; j < x; j++){
                if(grid[i][j] == 'x'){
                    dfs(i,j); 
                    ans++; 
                }
            }
        }
        

        printf("Case %d: %d\n", tc, ans); 
        ans = 0;

    }
    return 0;
}