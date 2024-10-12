/*
946E
AC
*/

#include <iostream>
#include <string>
#include <set>

using namespace std; 

void solve()
{
    int best = 0;
    string s; cin >> s; 

    set<int> need; 
    need.insert(s[0] - '0');
    for(int i = 1; i < s.length(); ++i){
        if(*need.begin() < s[i] - '0' && need.size() <= s.length() - i) best = i;
        if(s[i] != '0' && need.size() + 2 <= s.length() - i) best = i;
        auto it = need.find(s[i] - '0'); 
        if(it != need.end()) need.erase(it); 
        else need.insert(s[i] - '0');
    }
    //cout << best << "\n";
    if(best == 0 && s[0] == '1'){
        for(int i = 0; i < s.length() - 2; ++i){
            cout << 9; 
        }
        cout << "\n";
        return;
    }
    else{
        need.clear();
        for(int i = 0; i < best; ++i){
            cout << s[i]; 
            auto it = need.find(s[i] - '0'); 
            if(it == need.end()) need.insert(s[i] - '0'); 
            else need.erase(it);
        }
        int rem = s.length() - best; 
        int nines = rem - need.size();
        //drop 1
        if(need.size()+ 2<= rem && need.find(s[best] - 1 - '0') == need.end()){
            nines -= 2; 
            need.insert(s[best] - 1 - '0');
            cout << (char)(s[best] - 1); 
            for(int i = 0; i < nines; ++i) cout << 9;
            for(auto it = need.rbegin(); it != need.rend(); ++it){
                cout << *it; 
            }
            cout << "\n"; 
            return; 
        }
        else
        {
            auto it = need.lower_bound(s[best] - '0'); 
            it = prev(it);
            cout << *it; need.erase(it); 
            for(int i = 0; i < nines; ++i){
                cout << 9; 
            }
            for(auto it = need.rbegin(); it != need.rend(); ++it){
                cout << *it; 
            }
            cout << "\n"; 
        }
    }
}

int main(){

    int t; cin >> t; 
    while(t--){
        solve();
    }
    return 0;
}