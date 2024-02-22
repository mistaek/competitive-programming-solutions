/*
1884D
AC
*/

#include <iostream>
#include <set>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        long long n; cin >> n; 
        long long cnt[n+1] = {}, set[n+1] = {}, marked[n+1] = {};
        for(int i = 0; i < n; i++){
            int ai; cin >> ai; 
            ++cnt[ai]; 
            set[ai] = 1; 
        }

        long long ans = (n * (n-1))/2LL; 

        for(int d = 1; d <= n; d++){
            long long dcnt = 0, md = 1 - marked[d];
            if(!set[d]) continue; // no need to check
            for(int i = d; i <= n; i += d){
                dcnt += cnt[i];
                marked[i] += md;
                set[i] = 1; 
            }
            //cout << d << " " << cnt[d] << " " << md << " " << dcnt << "\n";

            ans -= md * (dcnt * (dcnt-1))/2LL; 
        }
        cout << ans << "\n";

    }
    return 0;
}