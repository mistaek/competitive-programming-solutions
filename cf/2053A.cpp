/*
2053A
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];

        bool pos = false; 
        for(int i = 0; i < n-1; ++i){
            int s = a[i], r = a[i+1]; 
            if(s > r) swap(s, r);

            if(2*s > r) pos = true;   
        }

        cout << (pos ? "YES\n" : "NO\n");
    }
    return 0; 
}