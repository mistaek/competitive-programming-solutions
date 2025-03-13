/*
2056C
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n]; 
        a[0] = a[1] = 1; 
        a[2] = 2; 
        a[n-1] = 2; 
        a[n-2] = 1; 
        int ctr = 2; 
        for(int i = 3; i < n-2; ++i){
            a[i] = ++ctr; 
        }

        for(int i = 0 ; i < n; ++i){
            if(i) cout << " "; 
            cout << a[i]; 
        }
        cout << "\n";
    }
    return 0;
}