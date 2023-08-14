/*
1790E
AC
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
    int t; cin >> t; 
    while(t--){
        long long a = 0, b = 0;
        long long x; cin >> x; 
        for(int i = 0; i <= 30; i++){
            if(x & (1 << i) && x & (1 << (i-1))){
                a = -1; 
                break; 
            }
        }
        if(x & 1) a = -1; 
        if(a == -1){
            cout << a << "\n"; 
            continue; 
        }
        for(int i = 0; i <= 30; i++){
            if(x & (1 << i)){
                a |= (1 << i); 
                a |= (1 << (i-1)); 
                b |= (1 << (i-1)); 
            }
        }
        cout << a << " " << b << "\n"; 
    }
    return 0;
}