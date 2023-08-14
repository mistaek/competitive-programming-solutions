/*
1717D
too slow... sad!
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>

using namespace std; 

const long long mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    
    long long n, k; cin >> n >> k; 
    long long tot = 1;
    for(int i = 0; i < n; i++){
        tot *= 2; 
        tot %= mod;
    }
    if(k >= n) cout << tot << "\n"; 
    else{
        long long win = 1; 
        //probably wrong cause of mod stuff
        long long diff;
        if(n >= 30){
            n--;
            diff = (tot + mod) /2; 
            diff %= mod; 
        }
        else diff = tot/2; 
        for(int i = 0; i < k; i++){
            win += diff; 
            if(n >= 30){
                n--;
                diff = (diff + mod) /2; 
                diff %= mod; 
            }
            else{
                diff /= 2;
                diff %= mod; 
            }
            win %= mod;
        }
        win %= mod;
        cout << win << "\n"; 
    }

}