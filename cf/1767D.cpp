/*
1767D
*/

#include <iostream>

using namespace std; 

int main(){
    int n; cin >> n; 
    int range = (1 << n); 
    int c = 1; 
    int f = 1;
    for(int i = 0; i < n; i++){
        char ch; cin >> ch; 
        if(ch == '0') c *= 2; 
        else f *= 2; 
    } 
    cout << f; 
    for(int i = f + 1; i <= range - c + 1; i++){
        cout << " " << i; 
    }
    cout << "\n";
    return 0; 
}