/*
1606C 
AC
*/
#include <cstdio>

int tene(int expt){
    int ret = 1;
    for(int i = 0; i < expt; i++) ret *= 10; 
    return ret; 
}

// holy i forgot how to write comments
int main(){
    int t; scanf("%d", &t);
    while(t--){
        long long n, k; scanf("%lld %lld", &n, &k);
        //printf("%d %d\n", n, k);
        long long d[n] = {}, g[n-1] = {}; 
        for(int i = 0; i < n; i++) scanf("%lld", &d[i]);
        for(int i = 1; i < n; i++) g[i - 1] = tene(d[i] - d[i-1]) - 1;
        
        long long j = 0, ans = 0; 
        k++;// make a number with k + 1 bills
        
        while(k > 0){
            if(j < n-1){
                if(k > g[j]){
                    k -= g[j]; 
                    ans += g[j] * tene(d[j]);
                }
                else{
                	ans += k * tene(d[j]);
                    k = 0;
                }
            }
            else{
            	ans += k * tene(d[n-1]);
                k = 0; 
                
            }
            j++;
        }
        printf("%lld\n", ans);

    }
    return 0;
}