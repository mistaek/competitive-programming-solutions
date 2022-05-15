/*
ccc 07s5
pretty sure i did this question already as well, but i cant remember the solution :blobwhy: - ac
*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
long long memo[30001][501];
long long psa[30001];
long long n, k, w; 

long long decision(long long idx, long long remb){
    if(idx >= n) return 0;
    if(remb == 0) return 0;
    if(memo[idx][remb] != -1) return memo[idx][remb];
    
    return memo[idx][remb] = max(decision(idx + 1, remb), psa[min(n-1, idx+w-1)] - ((idx > 0) ? psa[idx-1] : 0) + decision(idx+w, remb-1));
}

int main(){
    int tc; scanf("%d", &tc);
    while(tc--){
        scanf("%lld %lld %lld", &n, &k, &w);
        long long in;
        for(int i = 0; i < n; i++){
            scanf("%lld", &in); 
            psa[i] = ((i == 0) ? in : psa[i-1] + in);
            //printf("%d ", psa[i]);
            for(int j = 0; j <= k; j++){
                memo[i][j] = -1;
            }
        }
        //printf("\n");
        printf("%lld\n", decision(0, k)); 
    }
    return 0;
}