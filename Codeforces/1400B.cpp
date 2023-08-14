/*
1400B
AC
*/

#include <cstdio>
#include <algorithm>

using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long p, f; scanf("%lld %lld", &p, &f); 
        long long cs, cw; scanf("%lld %lld", &cs, &cw);
        long long s, w; scanf("%lld %lld", &s, &w); 
        
        long long ans = 0;
        if(w < s){
            swap(cs, cw); swap(s, w); 
        }
        for(long long i = 0; i <= min(p/s, cs); i++){
            long long tp = p, tf = f, tcs = cs, tcw = cw, ta1 = 0, ta2 = 0, a1 = 0, a2= 0;
            ta1 = i; 
            tp -= i * s; 
            tcs -= i; 
            ta1 += min(tp/w, tcw); 
            tcw -= min(tp/w, tcw);

            ta2 += min(tcs, tf/s); 
            tf -= s * min(tcs, tf/s); 
            ta2 += min(tf/w, tcw); 
            ans = max(ans, ta1 + ta2);
        }
        printf("%lld\n", ans);
        
        



    }
    return 0;
}