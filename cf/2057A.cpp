/*
2057A
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t;
    while(t--){
        long long n, m; 

        cin >> n >> m; 
        cout << 1LL + max(n, m) << "\n"; 
    }
    return 0;
}