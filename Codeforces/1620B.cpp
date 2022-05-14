/*
1620B
ac
*/

#include <cstdio>
#include <algorithm>
using namespace std; 
int main(){
    long long t; scanf("%lld", &t); 
    while(t--){
        long long w, h; scanf("%lld %lld", &w, &h); 
        long long ans =0 ;
        for(int i = 0; i < 2; i++){
            long long k; scanf("%lld", &k); 
            long long m1, m2; 
            scanf("%lld", &m1); 
            for(int j = 0; j< k-1; j++) scanf("%lld", &m2); 
            ans = max(ans, (m2-m1) * h);
        }
        for(int i = 0; i < 2; i++){
            long long k; scanf("%lld", &k); 
            long long m1, m2; 
            scanf("%lld", &m1); 
            for(int j = 0; j< k-1; j++) scanf("%lld", &m2); 
            ans = max(ans, (m2-m1) * w);
        }
        printf("%lld\n", ans);
    }
    return 0;
}