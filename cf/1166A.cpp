/*
1166A
*/

#include <iostream>

using namespace std; 

int main(){
ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 

    int n; cin >> n; 
    int cnt[26] = {}; 
    for(int i = 0; i < n; ++i){
        string name; cin >> name; 
        cnt[name[0] - 'a']++; 
    }

    int ans = 0; 
    for(int i = 0; i < 26; ++i){
        int split = cnt[i]/2, rem = cnt[i] - split; 
        ans += (split) * (split - 1) /2; 
        ans += (rem) * (rem-1)/2; 
    }

    cout << ans << "\n";
    return 0; 
}