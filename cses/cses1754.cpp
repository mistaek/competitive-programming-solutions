/*
cses 1754
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int a, b; cin >> a >> b; 
        if((a + b) % 3) cout << "NO\n"; 
        else if(a * 2 >= b && b * 2 >= a) cout <<"YES\n"; 
        else cout << "NO\n";
    }
    return 0;
}