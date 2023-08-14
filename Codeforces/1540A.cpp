/*
1540A
ac
*/

#include <cstdio>
#include <algorithm>

using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        long long a[n], psa[n] = {}; 
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            
        }
        sort(a, a+n); 
        for(int i = 1; i < n; i++){
            psa[i] = a[i]; 
            psa[i] += psa[i-1];
        }
        long long ans = 0;
        for(int i = 2; i < n; i++){
            ans += ((i-1)*a[i]) - psa[i-2];
        }
        printf("%lld\n", -ans);
    }
    return 0;
}