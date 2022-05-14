/*
CF1613D
AC
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long n; scanf("%lld", &n);
        long long ci[n+3] = {}, fci[n+3] = {1};
        long long ans = 0;
        for(int i = 0; i < n; i++){
            long long in; scanf("%lld", &in);
            ans += fci[in + 1] + fci[in] + ci[in+1];
            ans %= 998244353; 
            fci[in + 1] += fci[in + 1] + fci[in]; 
            fci[in+1] %= 998244353;
            if(in){
                ans += ci[in-1] + fci[in-1];
                ci[in-1] += ci[in-1] + fci[in-1];
                ci[in-1] %= 998244353;  
            }
            ci[in+1] += ci[in+1]; 
            ci[in+1] %= 998244353; 

            ans %= 998244353; 
        }
        ans %= 998244353;
        printf("%lld\n", ans);
    }
    return 0;
}