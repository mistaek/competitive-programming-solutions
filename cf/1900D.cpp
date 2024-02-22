/*
1900D
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        long long n; cin >> n; 
        vector<long long> a(n), f(1e5+1, 1), cnt(1e5+1, 0); 
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            ++cnt[a[i]];
        }

        for(int i = 1; i<= 100000; i++){
            cnt[i] += cnt[i-1]; 
        }

        long long ans = n * (n-1) * (n-2); //count all ones
        ans/= 6LL;
        //cout << ans << "\n";
        for(int i = 2; i <= 100000; i++){
            long long tot = 0, fi = f[i];
            for(int j = i; j <= 100000; j += i){
                long long cntj = cnt[j] - cnt[j-1]; 
                if(cntj){
                    long long numpj3 = (cntj * (cntj - 1) * (cntj-2))/6LL; 
                    long long numpj2 = (cntj * (cntj-1) * (n-cnt[j])) /2LL; 
                    long long numpj1 = (tot * (cntj * (cntj-1)))/2LL;
                    long long numpo = tot * cntj * (n-cnt[j]); //number of pairs using other
                    ans += numpj3 * (i - fi); 
                    ans += numpj2 * (i-fi);
                    ans += numpj1 * (i-fi);
                    ans += numpo * (i-fi);
                    tot += cntj; 
                    //cout << i << " " << j << " " << numpo << " " << numpj1 << " " << numpj2 << " " << numpj3 << "\n";
                }
                f[j] += i -fi;
            }
            //if(cnt[i]-cnt[i-1]) cout << i << " " << ans << "\n"; 

        }
        cout << ans << "\n";


    }
    return 0;
}