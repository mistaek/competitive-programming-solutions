/*
1944A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std; 

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        if(k >= n-1) cout << 1 << "\n"; 
        else cout << n <<"\n";
    }
    return 0;
}