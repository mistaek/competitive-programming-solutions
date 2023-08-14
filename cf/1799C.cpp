/*
1799C
AC (??)
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int cnt[26] = {}; 
        string s; cin >> s; 
        for(char c : s){
            cnt[c-'a']++;
        }
        int i1= 0, i2 = s.length() - 1; 
        int tot = s.length(); 
        int last = -1;
        for(int i = 0; i < 26; i++){
            if(cnt[i] == 0) continue; 
            if(last != -1){
                if(tot ==cnt[i]){
                    while(cnt[i] >= 2){
                        s[i1] = 'a' + i; 
                        s[i2] = 'a'+ i; 
                        cnt[i] -= 2; 
                        i1++; i2--;
                    }
                    if(cnt[i]) s[i1] = 'a' + i; 
                    s[i2]= 'a' + last; 
                    break; 
                }
                else{
                    while(i1 < i2){
                        if(cnt[i] == 0) i++; 
                        else{
                            s[i1] = 'a' + i; 
                            cnt[i]--;
                            i1++;
                        }
                    }
                    s[i2] = 'a' + last; 
                    break; 
                }
            }
            while(cnt[i] >= 2){
                s[i1] = 'a' + i; 
                s[i2] = 'a'+ i; 
                i1++; i2--;
                tot-=2; 
                cnt[i] -= 2; 
            }
            if(cnt[i]){
                last = i; 
                tot--;
            }

        }
        if(last != -1) s[i2] = 'a' + last; 
        cout << s << "\n";
    }

    return 0;
}