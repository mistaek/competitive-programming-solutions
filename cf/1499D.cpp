/*
1499D
AC SKULL 
*/

#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    vector<bool> isPrime(20000001, true);
    vector<int> primeCnt(20000001, 0); 
    isPrime[0] = isPrime[1] = false; 
    for(int i = 2; i < 20000001; ++i){
        if(isPrime[i]){
            for(int j = i; j < 20000001; j += i){
                ++primeCnt[j]; 
                isPrime[j] = false; 
            } 
            isPrime[i] = true; 
        }
    }
    int t; cin >> t; 
    while(t--){
        int c, d, x; cin >> c >> d >> x; 
        long long ans = 0; 

        for(long long i = 1; i * i <= x; ++i){
            if(x % i == 0){
                int cmulLCMdivG = x/i + 1LL*d; 
                if(cmulLCMdivG % c == 0) ans += 1LL << primeCnt[cmulLCMdivG/c]; 
                if(i*i == x) continue; 
                cmulLCMdivG = i + d; 
                if(cmulLCMdivG % c == 0) ans += 1LL << primeCnt[cmulLCMdivG/c];
            }
        }

        cout << ans << "\n";
        
    }
    return 0;
}