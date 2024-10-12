/*
2002A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> b[i];
        }
        int win1 = 1, win2 = 1;; 
        for(int i = 0; i < n; ++i){
            if(a[i] != b[i]) win1 = 0; 
            if(a[i] != b[n-1-i]) win2 =0;
        }
        if(win1 || win2) cout << "Bob\n";
        else cout << "Alice\n";
        
    }
    return 0;
}