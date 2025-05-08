/*
2108B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        long long n, x; cin >> n >> x; 
        if(x == 0){
            if(n == 1){
                cout << "-1" << "\n"; 
                continue; 
            }
            if(n % 2){
                cout << n +3 << "\n";
                continue;  
            }
            else{
                cout << n << "\n";
                continue; 
            }
        }
        if(x == 1){
            if(n % 2){
                cout << n <<"\n"; 
                continue; 
            }
            else{
                cout << n + 3 << "\n"; 
                continue; 
            }
        }

        // x is >=2; 
        int m = 0; 
        for(int i = 0; i <= 30; ++i){
            if(x & (1LL << i)){
                ++m; 
            }
        }
        if(m >= n){
            cout << x << "\n"; 
            continue; 
        }
        else{
            long long d = n - m; 
            if(d % 2) d+= 1;
            cout << d + x << "\n"; 
        }
    }
    return 0;
}