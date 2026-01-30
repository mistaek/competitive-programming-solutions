/*
1181C
AC, my binary lift was wrong.
*/
    
#include <iostream>
#include <vector>
    
using namespace std;
    
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m; cin >> n >> m;
    
    vector<vector<char>> g(n, vector<char>(m));
    vector<vector<vector<bool>>> eq(n, vector<vector<bool>>(m, vector<bool>(10, false))); // eq[i][j][k] is true if g[i][j] to g[i+2^k][j] are eq
    vector<vector<long long>> maxeq(n, vector<long long>(m, 0));
    vector<vector<long long>> max3eq(n, vector<long long>(m, 0));
    
    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < m; ++j){
            cin >> g[i][j];
        }
    }
    
    for(long long k = 0; k < 10; ++k){
        for(long long i = 0; i + (1 << k) < n; ++i){
            for(long long j = 0; j < m; ++j){
                if(k == 0) eq[i][j][k] = (g[i][j] == g[i+(1<<k)][j]);
                else eq[i][j][k] = (g[i][j] == g[i+(1<<k)][j]) && eq[i][j][k-1] &&  eq[i+(1<<(k-1))][j][k-1]; 
            }
        }
    }
    for(long long i = 0; i < n; ++i){
        for(long long j = 0; j < m; ++j){
            long long curans = 0;
            for(long long k = 9; k >=0; --k){
                if(eq[i + curans][j][k]){
                    curans += (1 << k);
                }
            }
            maxeq[i][j] = curans;
        }
    }
    
    for(long long i = 0; i < n; ++i) {
        for(long long j = 0; j < m; ++j){
            long long gap = maxeq[i][j] + 1;
            if(i + 3*(maxeq[i][j] + 1) > n) continue;
            if(maxeq[i][j] == maxeq[i+gap][j] && maxeq[i][j] <= maxeq[i+2*gap][j]) max3eq[i][j] = gap;
        }
    }
    
    long long ans = 0;
    for(long long i = 0; i < n; ++i){
        long long cur = 0;
        for(long long j = 0; j < m; ++j){
            if(j && max3eq[i][j] != max3eq[i][j-1]){
                //if (cur) cout << "Row " << i << ": rectangle from " << j-cur << " to " << j-1 << " of height " << 3*max3eq[i][j-1] << " and length " << cur << "\n";
                ans += (cur * (cur-1)/2) + cur;
                cur = 0;
            }
            else if(j && max3eq[i][j] == max3eq[i][j-1]){
                long long gap = max3eq[i][j];
                if(g[i][j] != g[i][j-1] || g[i+gap][j] != g[i+gap][j-1] || g[i+2*gap][j] != g[i+2*gap][j-1]) {
                    //if (cur) cout << "Row " << i << ": rectangle from " << j-cur << " to " << j-1 << " of height " << 3*max3eq[i][j-1] << " and length " << cur << "\n";
                    ans += (cur * (cur -1)/2) + cur; 
                    cur = 0;
                }
            }
            cur += (max3eq[i][j] > 0) ? 1 : 0; 
        }
        
        //if (cur) cout << "Row " << i << ": Rectangle from " << m-cur << " to " << m-1 << " of height " << 3*max3eq[i][m-1] << " and length " << cur << "\n";
    
        ans += (cur * (cur -1)/2) + cur; 
        cur = 0;
    }
    
    cout << ans << "\n";
    
    return 0;
}