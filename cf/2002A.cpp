/*
2002A
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc; 
    while(tc--){
        int n, m, k; cin >> n >> m >> k;
        cout << min(n, k) * min(m, k) << "\n";
    }
    return 0;
}