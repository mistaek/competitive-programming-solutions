/*
2128C
*/

#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        long long curmin = 0; 
        vector<long long> a(n); 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }        

        curmin = a[0]; bool pos = true; 
        for(int i = 1; i <n; ++i){
            if(a[i] >= curmin * 2){
                pos = false; 
            }
            curmin = min(curmin, a[i]); 
        }
        if(pos) cout << "YES\n"; 
        else cout << "NO\n"; 
    }
    return 0;
}