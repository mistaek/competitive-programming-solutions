/*
UVa 10496
[NAME] 
AC
*/
int xpos[11], ypos[11], dist[11][11], n; 
#include <cstdio>
#include <cstring>
#include <cmath>
#define min(a, b) ((a < b) ? a : b)
int memo[11][1 << 11]; //large
int tsp(int pos, int mask){
    if(mask == (1 << (n+1)) - 1){
        return dist[pos][0];
    }
    if(memo[pos][mask] != -1) return memo[pos][mask];

    int ans = (1 << 30); 
    for(int i = 0; i <= n; i++){
        if(i != pos && !(mask & (1 << i))){
            ans = min(ans, dist[pos][i] + tsp(i, mask | (1 << i)));
        }
    }
    return memo[pos][mask] = ans; 
} 

int main(){
    int TC; 
    scanf("%d", &TC);
    int w1, w2;  
    while(TC--){
        scanf("%d %d", &w1, &w2); 
        scanf("%d %d", &xpos[0], &ypos[0]);
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &xpos[i], &ypos[i]); 
        } 
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n;j++){
                dist[i][j] = abs(xpos[i] - xpos[j]) + abs(ypos[i] - ypos[j]); 
            }
        }
        memset(memo, -1, sizeof(memo));
        printf("The shortest path has length %d\n", tsp(0,1));
    }
    return 0; 
}