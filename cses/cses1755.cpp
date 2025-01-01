/*
1755
*/

#include <iostream>
#include <string>

using namespace std; 
int main(){
    int n; 
    string s; cin >> s; 
    n = s.length();
    int cnt[26] = {}; 
    for(int i = 0; i < n; ++i){
        cnt[s[i] - 'A']++;
    }
    bool odded = false, pos = true;
    int idx = 0;
    for(int i = 0; i < 26; ++i){
        //cout << cnt[i] << " "; 
        while(cnt[i] >= 2){
            s[idx] = 'A' + i; 
            s[n - idx - 1] = 'A' + i; 
            idx++;
            cnt[i] -= 2; 
        }
        if(cnt[i]){
            if(!odded && (n % 2)){
                s[n/2] = 'A' + i; 
                cnt[i]--; 
                odded = true; 
            }
            else{
                pos = false; 
                break; 
            }
        }
    }
    if(pos) cout << s << "\n"; 
    else cout << "NO SOLUTION\n"; 
    return 0;
}