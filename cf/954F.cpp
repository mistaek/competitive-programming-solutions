/*
954F
AC
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std; 
 
long long MOD=1e9 + 7;
vector<vector<long long>> base = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
vector<long long> state = {0, 0, 0};
vector<vector<long long>> mmult(const vector<vector<long long>> &a,const vector<vector<long long>> &b)
{
    vector<vector<long long>> ans = vector<vector<long long>>(a.size(), vector<long long>(b[0].size(), 0));
 
    for(int i = 0; i < a.size(); ++i){
        for(int j = 0; j < b[0].size(); ++j){
            for(int k = 0; k < b.size(); ++k){
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] %= MOD;
            }
        }
    }
 
    return ans; 
}
 
vector<vector<long long>> binexp(const vector<vector<long long>>& b, long long exp){
    vector<vector<long long>> ans = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, pow = b; 
 
    for(int i = 0; i < 62; ++i){
        if(exp & (1LL << i)){
            ans = mmult(pow, ans);
        }
        pow = mmult(pow, pow);
    }
 
    return ans;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m; cin >> n >> m; 
    vector<pair<pair<long long, long long>, long long>> obstacles; 
    for(int i = 0; i < n; ++i){
        long long a, l, r; 
        cin >> a >> l >> r; --a; --l; --r; 
        obstacles.push_back({{l, -1}, a}); 
        obstacles.push_back({{r+1, 1}, a});
    }
 
    sort(obstacles.begin(), obstacles.end());
    obstacles.push_back({{m, 0}, 0});
    long long curd = 0, curind = 0;
    vector<vector<long long>> curvec = {{0}, {1}, {0}};  
    while(curd < m - 1){
        if(curd < obstacles[curind].first.first - 1){
            curvec = mmult(binexp(base, obstacles[curind].first.first - curd - 1), curvec);
            curd = obstacles[curind].first.first - 1;
            //cout << curd << " " << curvec[0][0] << " " << curvec[1][0] << " " << curvec[2][0] << "\n"; 
        }
        state[obstacles[curind].second] += obstacles[curind].first.second;
        ++curind;
        if(state[0] == 0){
            base[0] = {1, 1, 0}; 
        }
        else base[0] = {0, 0, 0}; 
        if(state[1] == 0){
            base[1] = {1, 1, 1}; 
        }
        else base[1] = {0, 0, 0}; 
        if(state[2] == 0) base[2] = {0, 1, 1}; 
        else base[2] = {0, 0, 0};
    }
 
    cout << curvec[1][0] << "\n";
    return 0;
}