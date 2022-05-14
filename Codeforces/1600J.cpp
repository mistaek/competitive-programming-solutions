/*
1600J
AC - problem statement and testcases are really wack though
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std; 

int factory[3000][3000] = {}; 
int n, m;
int dirx[4] = {2, 0, -2, 0}, diry[4] = {0, 2, 0, -2}, dirwx[4] = {1, 0, -1, 0}, dirwy[4] = {0, 1, 0, -1}; 

int dfs(int x, int y){ // not actually xy
    if(x < 0 || y < 0 || x >= (1 + 2*n) || y >= (1 + 2 * m)) return 0;
    if(factory[x][y] == 1) return 0;
    factory[x][y] = 1; 
    int ret = 1; 
    for(int i = 0; i < 4; i++){
        if(factory[x + dirwx[i]][y + dirwy[i]] == 0){
            ret += dfs(x + dirx[i], y + diry[i]);
        }
    }
    return ret; 
}

int main(){
    scanf("%d %d", &n, &m);

    // coords are 1 + 2n, 1 + 2m
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int rm; scanf("%d", &rm); 
            if(rm & 8) factory[2 * i][1 + (2 * j)] = 1; 
            if(rm & 4) factory[1 + (2 * i)][2 + (2 * j)] = 1; 
            if(rm & 2) factory[2 + (2 * i)][1 + (2 * j)] = 1; 
            if(rm & 1) factory[1 + (2 * i)][2 * j] = 1;  
        }
    }
    vector<int> ans; 
    for(int i = 1; i < 1 + (2 * n); i += 2){
        for(int j = 1; j < (1 + (2*m)); j+= 2){
            if(factory[i][j] == 0){
                ans.push_back(dfs(i, j));
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for(int i = 0; i < ans.size(); i++){
        printf("%d ", ans[i]);
    }
    return 0;
}