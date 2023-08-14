/*
ccc08s3
ac
*/

//simple?

#include <cstdio>
#include <iostream>
#include <queue>

using namespace std; 

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int r, c; scanf("%d %d", &r, &c);
        char grid[r][c], dist[r][c];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                scanf(" %c", &grid[i][j]);
                dist[i][j] = -1;
            }
        }
        dist[0][0] = 1;
        queue<pair<int, int>> bfs; 
        bfs.push({0, 0});
        while(!bfs.empty()){
            pair<int, int> u = bfs.front(); bfs.pop();
            if(grid[u.first][u.second] == '+' || grid[u.first][u.second] == '|'){
                for(int i = -1; i < 2; i+=2){
                    if(u.first + i < 0 || u.first + i >= r) continue;
                    if(grid[u.first+i][u.second] == '*' || dist[u.first+i][u.second] != -1) continue; 
                    dist[u.first+i][u.second] = dist[u.first][u.second] + 1;
                    bfs.push({u.first+i, u.second});
                }
            }
            if(grid[u.first][u.second] == '+' || grid[u.first][u.second] == '-'){
                for(int i = -1; i < 2; i+=2){
                    if(u.second + i <0 || u.second + i >= c) continue; 
                    if(grid[u.first][u.second + i] == '*' || dist[u.first][u.second+i] != -1) continue; 
                    dist[u.first][u.second+i] = dist[u.first][u.second]+1; 
                    bfs.push({u.first, u.second+i});
                }
            }
        }
        printf("%d\n", dist[r-1][c-1]);
    }
    return 0;
}