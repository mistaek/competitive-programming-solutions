/*
1004D
ac, im bad
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n, q; cin >> n >> q; 
    vector<long long> cnt(32, 0);
    for(int i = 0; i < n; ++i){
        long long a; cin >> a; 
        int j = 0; 
        while(a != 1){
            a/=2; 
            ++j;
        }
        cnt[j]++;
    }

    for(int i = 0; i < q; ++i){
        long long b; cin >> b; 
        vector<long long> dup= cnt; 
        long long ans = 0;
        bool pos = true; 
        for(int j = 0; j < 32; ++j){
            //use current coins
            if(b & (1 << j)){
                //cout << b << " " << j << "\n"; 
                long long need =1;
                for(int k = j; need && k >= 0; --k){
                    long long used = min(dup[k], need);
                    //cout << k << " " << used << "\n"; 
                    dup[k] -= used; 
                    need -= used; 
                    ans += used; need *= 2; 
                }
                if(need) pos = false; 
            }
        }
        if(pos)cout << ans << "\n";
        else cout << "-1\n";
    }
    return 0;
}