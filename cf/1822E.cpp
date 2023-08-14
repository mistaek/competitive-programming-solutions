/*
1822E
AC
*/

#include <iostream>
#include <string>
#include <set>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int ans = 0;
        int cnt[26] = {}, dupes[26] = {};
        string s; cin >> s; 
        if(n % 2) ans = -1; 
        if(ans == -1){
            cout << ans << "\n";
            continue;
        }
        for(int i = 0; i < n/2; i++){
            cnt[s[i] - 'a']++; 
            cnt[s[n-i-1]-'a']++;
            if(cnt[s[i]-'a'] > (n/2) || cnt[s[n-i-1]-'a'] > (n/2)){
                ans = -1; break; 
            }
            if(s[i] == s[n-i-1]) {
                dupes[s[i]- 'a']++; 
                ans++;
            }
        }
        if(ans == -1) cout << ans << "\n";  
        else{
            for(int i = 0; i < 26; i++){
                while(dupes[i]){
                    int k = -1; 
                    for(int j = 0; j < 26; j++){
                        if(j != i && dupes[j]){
                            if(k == -1) k = j; 
                            else if(dupes[k] < dupes[j]) k = j; 
                        }
                    }
                    if(k == -1) break; 
                    else{
                        dupes[i]--; 
                        dupes[k]--; 
                        ans--;
                    }
                }
            }
            cout << ans << "\n";
        }


    }
    return 0;
}