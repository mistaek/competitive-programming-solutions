/*
1673C
AC
*/
#include <iostream>
#include <vector>

using namespace std; 

int mod = 1e9+7;
vector<int> pl; 
vector<vector<int>> memo(500, vector<int>(40001, -1));

int compute(int idx, int n){        
    if(n == 0) return 1;
    if(idx >= pl.size()) return 0; 
    if(pl[idx] > n) return 0;
    if(memo[idx][n] != -1) return memo[idx][n];
    

    memo[idx][n] = compute(idx + 1, n) + compute(idx, n - pl[idx]);
    return memo[idx][n] %= mod;
    

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    
    for(int i = 1; i <= 40000; i++){
        int temp = i; 
        bool ans = true;
        int pow = 1; 
        while(temp /= 10) pow *= 10;
        temp = i;
        while(pow >= 1){
            int last = temp % 10;
            int first = temp/pow;
            if(first != last){ ans = false; break;}
            temp -= first * pow; 
            temp /= 10;
            pow /= 100;
        }
        if(ans) pl.push_back(i);
    }
    
    for(int i = 1; i <= 40001; i++){
        compute(0, i);
    }

    int t; cin >> t; 
    while(t--){
        int in; cin >> in; 
        cout << memo[0][in] << "\n";
    }

    
    return 0;
}