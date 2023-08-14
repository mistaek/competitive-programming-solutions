/*
ccc15j5
ac - read editorial: how would you think of this on your own?
*/

#include <cstdio>
#include <cstring> 

#define min(a, b) ((a < b) ? a : b)
int n, k; 
int dp[255][255]; //length, sum; 

int main(){
    scanf("%d %d", &n, &k);
    dp[1][1] = 1; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            dp[i+1][j+1] += dp[i][j];
            if(j + i < 255) dp[i][j+i] += dp[i][j];
        }
    }
    /*for(int i = 1; i <=n; i++){
        for(int j = 1; j <=n; j++) printf("%d ",dp[i][j]);
        printf("\n");
    }*/
    printf("%d\n", dp[k][n]);
    return 0;
}