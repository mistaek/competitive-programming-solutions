/*
2133A
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int cnt[101] = {}; 
        bool pos = false; 
        for(int i = 0; i < n; ++i){
            int a; cin >> a; 
            cnt[a]++; 
            if(cnt[a] >= 2) pos=true; 
        }
        if(pos) cout << "YES\n"; 
        else cout << "NO\n"; 
    }
    return 0;
}