/*
1717A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        cout << n + (2* (n/2)) + (2 * (n/3)) << "\n"; 
    }
    return 0;
}