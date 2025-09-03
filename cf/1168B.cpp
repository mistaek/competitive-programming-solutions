/*
1168B
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    string s; 
    cin >> s; 

    int n = s.length(); 
    long long ans = 0; 
    for(int i = 0; i < n-2; ++i){
        if(i + 8 < n){
            ans += n - (i + 8); // any selection > 9 is good
        }
         
        for(int j = i+2; j < min(n, i+ 8); ++j){
            bool foundTriplet = false;
            for(int x = i; x <= j-2; ++x){ 
                for(int k = 1; k <= 4; ++k){
                    if(foundTriplet || x + 2*k > j){
                        break; 

                    }
                    if(s[x] == s[x + k] && s[x] == s[x + 2*k]) foundTriplet = true; 
                }
                if(foundTriplet)break; 
            }
            if(foundTriplet) ans++; 
        }
    }
    cout << ans << "\n";
    return 0;
}