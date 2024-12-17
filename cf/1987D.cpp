/*
1987D
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std; 
        
vector<pair<int, int>> s1;

int dp[5003][5003] = {};

int main(){
    int t; cin >> t;
    while(t--){
        s1.clear();
        int n; cin >> n; 
        int a[n]; 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }

        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                dp[i][j] = 0;
            }
        }

        sort(a, a+n); 
        int cur = a[0], cnt = 0; 
        for(int i = 0; i < n; ++i){
            if(a[i] == cur) ++ cnt; 
            else{
                s1.push_back({cur, cnt}); 
                cur = a[i]; 
                cnt = 1; 
            }
        }
        s1.push_back({cur, cnt}); 

        for(int i = s1.size() - 1; i >= 0; --i){
            for(int j = n-1; j>= 0; --j){
                dp[i][j] = dp[i+1][j+1];
                if(j >= s1[i].second){
                    dp[i][j] = max(dp[i][j], 1 + dp[i+1][j-s1[i].second]);
                }
            }        
        }
        
        /*for(int i = 6; i >=0; --i){
            for(int j = 0; j <= 6; ++j){
                cout << dp[i][j] << " "; 
            }
            cout << "\n";
        }*/

        cout << (int)s1.size() - dp[0][0] << "\n";
    }
    return 0;
}