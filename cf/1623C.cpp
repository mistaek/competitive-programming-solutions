/*
1623C
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        long long a[n], lo = 1e9, hi = 0; 
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]); 
            lo = min(lo, a[i]); 
            hi = max(a[i], hi);
        }

        while(lo + 1 < hi){
            long long mid = (lo + hi)/2; 
            //printf("%lld %lld %lld\n", lo, mid,  hi);
            
            long long b[n] = {}; bool t= true; 
            for(int i = n-1; i >= 0; i--){
               
                
                b[i] += a[i];
                if(i - 2 >=0){
                    long long d = min((b[i] - mid)/3, a[i]/3); 
                    d = max(d, 0LL);
                    b[i] -= 3 * d;
                    b[i-1] += d; 
                    b[i-2] += 2*d; 
                }
                //printf("%lld ", b[i]); 
                if(b[i] < mid){ t= false; break; }
                
            }
            //printf("\n");
            if(t) lo = mid; 
            else hi = mid;
        }
        long long b[n] = {}; bool t= true; 
            for(int i = n-1; i >= 0; i--){
               
                
                b[i] += a[i];
                if(i - 2 >=0){
                    long long d = min((b[i] - hi)/3, a[i]/3); 
                    d = max(d, 0LL);
                    b[i] -= 3 * d;
                    b[i-1] += d; 
                    b[i-2] += 2*d; 
                }

                if(b[i] < hi){ t= false; break; }
                
        }
        if(t) printf("%lld\n", hi); 
        else printf("%lld\n", lo);
    }
    return 0;
}