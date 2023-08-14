/*
uva 10653
ray
AC
*/

//bfs/dfs on a matrix

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring> 

using namespace std; 

int dirx[4] = {1, -1, 0, 0}; 
int diry[4] = {0, 0, 1, -1};

int main(){

    int r, c; 
    while(scanf("%d %d", &r, &c), r){
        int grid[r][c] = {};
        for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) grid[i][j] = -2;
        int rw; scanf("%d", &rw); 
        while(rw--){
            int rn; scanf("%d", &rn); 
            int nc; scanf("%d", &nc); 
            while(nc--){
                int cb; 
                scanf("%d", &cb); grid[rn][cb] = -1; 
            }
        }
        int sr, sc, er, ec; scanf("%d %d %d %d", &sr, &sc, &er, &ec); 

        queue<pair<int, int>> q; 
        grid[sr][sc] = 0;
        q.push({sr, sc});

        while(!q.empty()){
            pair<int, int> v = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                if(v.first + dirx[i] >= r || v.first + dirx[i] < 0) continue; 
                if(v.second+ diry[i] >= c || v.second + diry[i] < 0) continue; 
                if(grid[v.first +dirx[i]][v.second+diry[i]] == -2){
                    grid[v.first +dirx[i]][v.second+diry[i]] = grid[v.first][v.second] + 1;
                    q.push({v.first+dirx[i], v.second+diry[i]});
                }
            }
        }
        /*
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        */
        printf("%d\n", grid[er][ec]);
    }
    return 0;
}