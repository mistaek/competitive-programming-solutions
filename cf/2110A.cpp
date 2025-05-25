/*
2110A
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n]; 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }
        sort(a, a + n); 
        
        int ops = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] % 2 != a[n-1] % 2){
                ++ops; 
            }
            else break; 
        }
        int ops2 = 0; 
        for(int i = n-1; i >= 0; --i){
            if(a[i] % 2 != a[0] % 2){
                ++ops2; 
            }
            else break; 
        }
        cout << min(ops, ops2) << "\n"; 
    }
    return 0;
}