/*
1619B
WIP
*/

#include <cstdio>

int main(){
    long long sqrs[100001], cbs[1001], hexs[100];
    for(long long i = 1; i <= 100000; i++) sqrs[i] = i*i; 
    for(long long i = 1; i <= 1000; i++) cbs[i] = i*i*i; 
    for(long long i = 1; i < 100; i++) hexs[i] = i * i * i * i * i * i; 
    int t; scanf("%d", &t); 
    while(t--){
        long long n; scanf("%lld", &n); 
        long long ans = 0;
        for(int i = 1; i <= 100000; i++){
            if(sqrs[i] <= n) ans++;
        }
        for(int i = 1; i <= 1000; i++){
            if(cbs[i] <= n) ans++;
        }
        for(int i = 1; i < 100; i++){
            if(hexs[i] <= n) ans--; 
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}