/*
1864
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int x; cin >> x; 
        int k = 0, mx = 0;
        for(int i = 0; i < 31; i++){
            if(x & (1 << i)){k++; mx = i;}
        }
        cout << mx + k << "\n";
        cout << x; 
        for(int i = 0; i < mx; i++){
            if(x & (1 << i)){
                x -= (1 << i); 
                cout << " " << x; 
            }
        }
        for(int i = 0; i < mx; i++){
            x/=2; 
            cout << " " << x;
        }
        cout << "\n";

    }
    return 0;
}