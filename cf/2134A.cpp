/*
2134A
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int tc; cin >> tc;
    while(tc--){
        int n, a, b; cin >> n >> a >> b; 
        if(n % 2){
            if(b % 2 == 0){
                cout <<"NO\n"; 
            }
            else if(a > b && a % 2 == 0){
                cout << "NO\n"; 
            }
            else cout << "YES\n"; 
        }
        else{
            if(b % 2){
                cout << "NO\n"; 
            }
            else if(a > b && a % 2){
                cout << "NO\n"; 
            }
            else cout << "YES\n"; 
        }
    }
    return 0;
}