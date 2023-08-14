/*
1778C
AC
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        string a, b; cin >> a >> b; 
        int cnt[26] = {},counter = 1;
        for(int i = 0; i < n; i++){
            if(!cnt[a[i] - 'a']){
                cnt[a[i] -'a'] = counter++;
                //cout << a[i] << " " << counter - 1 << "\n"; 
            }
        }
        long long best = 0;
        for(int i = 0; i < 1024; i++){
            int bitcnt = 0;
            for(int j = 0; j < 10; j++){
                if(i & (1 << j)){
                    bitcnt++; 
                }
            }
            if(bitcnt != k) continue; 
            long long ans = 0, streak = 0;
            for(int j = 0; j < n; j++){
                if(a[j] == b[j] || i & (1 << (cnt[a[j]- 'a']-1))){
                    streak++; 
                }
                else{
                    ans += (streak*(streak+1))/2;
                    streak = 0; 
                }
            }
            ans += (streak*(streak+1))/2;
            best = max(best, ans);
        }

        cout << best << "\n";
    }
    return 0;
}