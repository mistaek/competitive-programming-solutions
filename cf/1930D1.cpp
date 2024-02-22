/*
1930D1
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        string s; cin >> s; 
        long long ans = 0;
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j < s.length(); j++){
                int nxt = -2; 
                for(int k = i; k <= j; k++){
                    if(s[k] == '1' && abs(k -nxt) > 1){
                        nxt = k+1; 
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}