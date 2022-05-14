/*
1582A
WIP
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        long long z= 0, o =0 , ans = 0;
        for(int i = 0; i < n; i++){
            long long in; scanf("%lld", &in); 
            if(in == 1) o++; 
            else if(in == 0) z++; 
        }
        ans = o; 
        for(long long i = 0; i < z; i++) ans *= 2; 
        printf("%lld\n", ans);
    }
    return 0;
}