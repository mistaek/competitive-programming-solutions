/*
1822G1
wip
*/

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std; 
long long cnt[1000001] = {};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<long long> a; 
        
        for(int i = 0; i < n; i++){
            long long in; cin >> in; 
            if(cnt[in] == 0){
                a.push_back(in);
            }
            cnt[in]++;
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        for(int i = 0; i < a.size(); i++){
            if(cnt[a[i]] >= 3){
                ans += cnt[a[i]] * (cnt[a[i]] - 1) * (cnt[a[i]] - 2);
            }
            for(int j = 2; j <= 1000; j++){
                long long x = a[i], y = x * j, z = y * j; 
                if(z > 1000000LL){
                    break; 
                }
                if(cnt[y] && cnt[z]){
                    ans += cnt[x] * cnt[y] * cnt[z];
                }
            }
        }
        for(int i = 0; i < a.size(); i++){
            cnt[a[i]] = 0;
        }
        cout << ans << "\n";
    }
    return 0;
}