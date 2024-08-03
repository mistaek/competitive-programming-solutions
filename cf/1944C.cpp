/*
1944C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n], cnt[n] = {}; 
        for(int i = 0; i < n; ++i){ cin >> a[i]; ++cnt[a[i]];}
        int singleton = 0, ans = 0;
        for(int i = 0; i < n; ++i){
            if(cnt[i] == 0){
                ans = i; 
                break; 
            }
            if(cnt[i] == 1){
                ++singleton;
                if(singleton == 2){
                    ans = i; 
                    break; 
                } 
            }
            ++ans; 
        }
        cout << ans << "\n";
    }
    return 0;
}