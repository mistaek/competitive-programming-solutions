/*
ccc07s5
wip
*/

#include <cstdio>

#define max(a, b) ((a > b) ? a : b)
int psa[30000], arr[30000];
int n, k, w;
int dp[30005][505]; //remw

//no werk, do late
//see MOCK version, ac
int solve(int ind, int remw){
    if(ind >= n) return 0;
    if(remw == 0) return dp[ind][0] = 0;
    if(dp[ind][remw] != 0) return dp[ind][remw]; 
    int over = 0; 
    if(ind >= n-w) over = n - ind; 
   
    return dp[ind][remw] = max( solve(ind+1, remw-1) + psa[ind + w - 1-over] - ((ind == 0) ? 0 : psa[ind -1]) , solve(ind +1, remw));

}
int main(){
    int tc; scanf("%d", &tc); 
    while(tc--){
         scanf("%d %d %d", &n, &k, &w);
        
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(i == 0) psa[i] = arr[i]; 
            else psa[i] = psa[i-1] + arr[i]; 
        }
        printf("%d\n", solve(0, k));
        

    }
    return 0;
}