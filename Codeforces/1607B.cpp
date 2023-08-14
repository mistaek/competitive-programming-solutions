/*
1607B
WIP
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long x, n; scanf("%lld %lld", &x, &n);
        long long ans = 0;
        if(n % 4 == 0) printf("%lld\n", x); 
        else{
            if(n % 4 == 1) ans = -n; 
            if(n % 4 == 2) ans = 1;
            if(n % 4 == 3) ans = n + 1;
            if(x % 2) ans = -ans; 
            printf("%lld\n", x + ans);
        }
    }
    return 0;
}