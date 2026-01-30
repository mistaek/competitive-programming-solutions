/*
2191A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<int> a(n), cnt(101, 0);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            cnt[a[i]]++;
        }

        if(cnt[0] == 0) cout << "NO\n";
        else if(cnt[0] == 1) cout << "YES\n";
        else if(cnt[1]) cout << "YES\n";
        else cout << "NO\n";
    }    
    
    return 0;
}