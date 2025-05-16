/*
1618C
ac - something weird went wrong and i dont know what it was
*/

#include <cstdio>

long long gcd(long long a, long long b){
    if(a == 0) return b; 
    return gcd(b % a, a);
}

int main(){
    int t; 
    scanf("%d", &t);
    while(t--){
        int n; scanf("%d", &n); 
        long long a[n] = {};
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);

        }

        long long g1 = a[0], g2 = a[1];
        for(int i = 0; i < n; i+= 2){
            g1 = gcd(g1, a[i]);
        }
        for(int i = 1; i < n; i+= 2){
            g2 = gcd(g2, a[i]);
        }
        if(g1 == g2) printf("0\n");
        else{
            bool t1 = true; 
            for(int i = 0 ; i < n; i+= 2){
                if(a[i] % g2 == 0) t1 = false; 
            }
            if(t1){
                printf("%lld\n", g2); 
                continue; 
            }
            t1 = true; 
            for(int i = 1; i < n; i += 2){
                if(a[i] % g1 == 0) t1 = false; 
            }
            if(t1){
                printf("%lld\n", g1); 
                continue; 
            }
            printf("0\n");
        }
    }
    return 0;
}