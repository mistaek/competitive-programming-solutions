/*
1606B
ac
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t);
    while(t--){
        long long n, k; scanf("%lld %lld", &n, &k);
        n--;
        long long p2 = 1;
        long long ans = 0;
        while(p2 < k && n > 0){
            ans++; 
            n -= p2; 
            p2 *= 2; 
        }
        if(n <= 0){
            printf("%lld\n", ans); 
            continue; 
        }
        ans += (n/k); 
        if(n % k) ans++;
        printf("%lld\n", ans);
    }
    return 0;
}