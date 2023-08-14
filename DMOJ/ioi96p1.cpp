/*
ioi 96 p1
ac: clsasic dp
*/

#include <cstdio>
#define max(a, b) ((a > b) ? a : b)
int main(){
    int n; scanf("%d", &n);
    int arr[n], psa[n]; for(int i =0; i < n; i++){ scanf("%d", &arr[i]); psa[0] = arr[0]; if(i) psa[i] = psa[i-1] + arr[i]; }

    int dp[n][n]; //max score in range i .. j inclusive. 

    for(int i = 0; i < n; i++) dp[i][i] = arr[i];
    for(int d = 1; d < n; d++){
        for(int i = 0; i < n; i++){
            if(i+ d <n){
                dp[i][i+d] = arr[i] + (psa[i+d] - psa[i] - dp[i+1][i+d]);
                int second = arr[i+d] + (psa[i+d-1] - dp[i][i+d-1]); if(i) second -= psa[i-1];
                dp[i][i+d] = max(dp[i][i+d], second); 
            }
        }
    }
    printf("%d %d\n", dp[0][n-1], psa[n-1] - dp[0][n-1]);
    return 0;
}