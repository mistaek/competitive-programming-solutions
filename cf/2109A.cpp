/*
2109A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
#include <map> 
#include <functional>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int min = 0;
        int n; cin >> n; 
        bool liar = false; 
        bool zero = false; 
        for(int i = 0; i < n; ++i){
            int a; cin >> a; 
            if(a == 0) zero = true; 
            if(min > a) liar = true; 

            min = 1-a; 
        }

        if(liar || !zero) cout << "YES\n"; 
        else cout << "NO\n"; 
    }
    return 0;
}