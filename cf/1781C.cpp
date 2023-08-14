/*
1781C
AC
*/

#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        string str; cin >> str; 
        int cnt[26] = {}; 
        for(int i = 0; i < n; i++){
            cnt[str[i] - 'a']++;
        }
        int ans = n, bu[26] = {}, bf = 1;
        for(int i = 1; i <= 26; i++){
            if(n % i == 0){
                //select letters
                int f = n/i;
                int u[26] = {};
                for(int l = 0; l < i; l++){
                    int c = 0;
                    for(int j = 0; j <26; j++){
                        if(u[c] && !u[j]) c = j;
                        if(!u[j] && max(f - cnt[j], 0) < max(f - cnt[c], 0)) c = j;
                    }
                    u[c] = 1; 
                }
                int tempans = 0;
                for(int j = 0; j < 26; j++){
                    if(u[j]) tempans += max(f - cnt[j], 0);
                }
                if(tempans < ans){
                    ans = tempans; 
                    for(int j = 0; j < 26; j++) bu[j] = u[j];
                    bf = f;
                }
            }
        }
        stack<int> s; 
        for(int i = 0; i < 26; i++){
            if(cnt[i] < bf && bu[i]) s.push(i);
        }

        for(int i = 0; i < n; i++){
            if(!bu[str[i] - 'a']){
                cnt[str[i] - 'a']--;
                str[i] = 'a' + s.top(); 
                cnt[s.top()]++; 
            
                if(cnt[s.top()] == bf) s.pop();
            }
            else if(cnt[str[i] - 'a'] > bf){
                cnt[str[i] - 'a']--; 
                cnt[s.top()]++; 
                str[i] = 'a' + s.top(); 
                if(cnt[s.top()] == bf) s.pop();
            }
        }
        cout << ans << "\n" << str << "\n";
    }
    return 0;
}