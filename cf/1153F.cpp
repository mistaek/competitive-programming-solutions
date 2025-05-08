/*
1153F
*/

#include <iostream>
#include <algorithm>

using namespace std; 

const int N = 4005, K = 2005; 

int dp[N][K][2] = {}; 
//int dp2[N][K][2] = {};
//using editorial

int mod = 998244353;

inline int mult(int a, int b){
    return 1LL*a*b% mod; 
}
inline int add(int a, int b){
    return a+b%mod;
}

int binexp(int a, int e){
    int ans = 1; 
    int pow = a; 
    for(int i = 0; i < 30; ++i){
        if((1 << i) & e){
            ans = mult(ans, pow); 
        }
        pow = mult(pow, pow); 
    }
    return ans; 
}

int inv(int a){
    return binexp(a, mod-2); 
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int n, k, l; cin >> n >> k >> l; 
    //can ignore l
    dp[0][0][0] = 1; //= dp2[0][0][0] = 1;

    for(int i = 0;i < 2*n+1; ++i){
        for(int j = 0; j < n+1; ++j){
            //dp2[i+1][j][1] = add(dp2[i+1][j][1], dp2[i][j][0]);

            if(j >=k){
                dp[i+1][j][1] = add(dp[i+1][j][1], dp[i][j][0]);
            }
            for(int k = 0; k < 2; ++k){
                if(i + j < 2 * n + k){
                    dp[i+1][j+1][k] = add(dp[i+1][j+1][k], dp[i][j][k]);
                    //dp2[i+1][j+1][k] = add(dp2[i+1][j+1][k], dp2[i][j][k]);
                }
                if(j){
                    dp[i+1][j-1][k] = add(mult(j,  dp[i][j][k]), dp[i+1][j-1][k]);
                    //dp2[i+1][j-1][k] = add(mult(j,  dp2[i][j][k]), dp2[i+1][j-1][k]);
                } 
            }
        }
    }


    
    
    //cout << dp[2*n+1][0][1] << " " << dp2[2*n+1][0][1] << "\n";
    //cout << mult(mult(dp[2*n+1][0][1], l), inv(dp2[2*n+1][0][1])) << "\n"; 
    ///*
    int fac =1; 
    for(int i = n+1; i <= 2*n+1; ++i){
        fac = mult(fac, i);
    }

    cout << mult(mult(dp[2*n+1][0][1], binexp(2, n)), mult(l, inv(fac)))<< "\n";
    //*/

    return 0;
}