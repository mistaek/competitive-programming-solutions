/*
1624D
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std; 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int t; 
    cin >> t; 
    while(t--){
        int k, n; cin >> n >> k; 
        string str; cin >> str; 

        int cnt[26] = {};
        for(int i = 0; i < str.length(); i++){
            cnt[str[i] - 'a']++;
        }
        int np = 0; 
        for(int i = 0; i < 26; i++){
            np += cnt[i]/2; 
        }

        int ans = np/k; 
        ans *= 2; 
        if(n - (k * ans) >= k) ans++; 
        cout << ans << "\n";
        
    }

    return 0;
}