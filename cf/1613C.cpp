/*
CF1613C
AC
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t);
    while(t--){
        long long n, h; scanf("%lld %lld", &n, &h);
        long long times[n], gaps[n-1];
        for(long long i = 0; i < n; i++){
            scanf("%lld", &times[i]); 
            if(i) gaps[i-1] = times[i] - times[i-1]; 
        }

        // solving
        sort(gaps, gaps+n-1); 
        bool out = false; 
        for(int i = 0; i < n-1; i++){
            long long s = gaps[i]; //selected
            long long v = 1, sm = 0, ans = 0;
            for(int i = 0; i < n-1; i++){
                if(gaps[i] < s) sm += gaps[i]; 
                else v++; 
            }
            if((h-sm) % v ==0) ans = (h-sm)/v; 
            else ans = ((h-sm)/v) +1; 
            if(ans <= s){
                printf("%lld\n", ans); out = true; break;
            }
        }
        if(!out){
            long long sm = 0, v = 1, ans = 0; 
            for(int i = 0; i < n-1; i++){
                sm += gaps[i]; 
            }
            if((h-sm) % v ==0) ans = (h-sm)/v; 
            else ans = ((h-sm)/v) +1; 
            printf("%lld\n", ans);
            
        }
    }
    return 0;
}