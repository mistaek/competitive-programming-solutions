/*
2055B
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<long long> a(n), b(n); 
        long long need = 0, gap = 0;
        for(int i = 0; i < n; ++i) cin >> a[i]; 
        for(int i = 0; i < n; ++i){
            cin >> b[i];
            if(a[i] < b[i]){
                need++; 
                gap = b[i] - a[i]; 
            }
        }

        if(need >= 2){
            cout << "NO\n"; 
        }
        else{
            bool pos = true; 
            for(int i = 0; i < n; ++i){
                if(a[i] >= b[i] && a[i] - b[i] < gap) pos = false; 
            }
            if(pos) cout << "YES\n"; 
            else cout << "NO\n";
        }
    }
    return 0;
}