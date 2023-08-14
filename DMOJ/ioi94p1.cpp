/*
ioi94p1
ac
*/

#include <cstdio>
#define max(a, b) ((a > b) ? a : b)
int n, triangle[105][105], dp[105][105];
int main(){
    scanf("%d", &n); 
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < i; j++){
            scanf("%d", &triangle[i][j]);
        }
    }
    
    for(int i = n; i > 0; i--){
        for(int j = 0; j < i; j++){
            dp[i][j] = max(triangle[i][j] + dp[i+1][j], triangle[i][j] + dp[i+1][j+1]);
        }
    }
    printf("%d\n", dp[1][0]);
    
    return 0;
}