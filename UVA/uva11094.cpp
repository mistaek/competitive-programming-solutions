/*
uva 11094
ray
AC
*/

#include <cstdio>
#include <cctype>
#include <cstring>
//god save meeeeeeeeeeeeeeeeeeeeeeeee

int m, n;
char map[21][21]; int v[21][21] = {};
char land;
int ans, sum; 
int dirx[] = {1, 0, -1, 0};
int diry[] = {0, 1, 0, -1};
int x, y; 

//finallyy done, too many small errors added up
//plan it, then execute, making sure not to make mistakes. backtracking is much worse than doing it right the first time.
void dfs(int i, int j){
    if(i < 0 || i >= m) return; 
    if(j <0 ) j = n-1; 
    if(j >= n) j = 0;
    if(map[i][j] != land || v[i][j] != 0) return; 
    v[i][j] = 1;  
    sum++;
    for(int d = 0; d < 4; d++){
        dfs(i + dirx[d], j + diry[d]);
    }
} 

int main(){
    while(scanf(" %d %d", &m, &n) != EOF){
        memset(v, 0, sizeof(v));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf(" %1c",&map[i][j] );
                map[i][j] = toupper(map[i][j]);
                
            }

        }

        scanf(" %d %d", &x, &y); 
        land = map[x][y];
        dfs(x,y); 
        ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                sum = 0; 
                dfs(i,j);
                if(sum > ans) ans = sum;
            }
        }

        printf("%d\n", ans);
    } 
    
    return 0;
}