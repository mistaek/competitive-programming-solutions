/*
1848D
AC
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        long long ans = 0;
        long long s, k; cin >> s >> k; 

        if(s % 10 == 0){
            cout << s * k << "\n";
        }
        else if(s % 10 == 5){
            cout << max(s * k, (s+5) * (k-1)) << "\n";
        }
        else{
            if(s % 2){
                ans = max(ans, k * s); 
                s += (s % 10); 
                --k; 
            }
            for(int i = 0; i < 4; ++i){
                if(k == 0) break; 
                long long lo = 0, hi = k; 
                while(lo < hi-100){
                    long long l = lo + (hi - lo)/3; 
                    long long r = hi - (hi - lo)/3; 
                    l -= l % 4; 
                    if(r % 4) r += 4 - r%4; 

                    long long xl = l * 5LL, xr =r*5LL;

                    long long ansl = (k - l) * (s + xl), ansr = (k - r) * (s + xr);
                    if(ansl < ansr){
                        lo = l; 
                    }
                    else hi = r;
                }
                while(lo <= hi){
                    long long xlo = lo * 5LL, anslo = (k-lo) * (s+xlo); 
                    //cout << lo << " " << k << " " << anslo << "\n";
                    ans = max(ans, anslo);
                    lo += 4; 
                }
                s += (s%10); 
                --k; 
            }
            
            cout << ans << "\n";
        }
    }
    return 0;
}