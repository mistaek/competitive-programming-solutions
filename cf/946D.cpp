/*
946D
AC, im so bad lol
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std; 

vector<vector<int>> times; 
vector<vector<int>> dp;
vector<vector<int>> ans; 

int n, m, k; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	cin >> n >> m >> k; 

	times =	vector<vector<int>>(n); 
	ans = vector<vector<int>>(n, vector<int>(k+1, 1e9)); 
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < m; ++j){
			char c; cin >> c; 
			if(c == '1') times[i].push_back(j); 
		}
		if(times[i].empty()) dp.push_back(vector<int>(k+1, 0)); 
		else dp.push_back(vector<int>(k+1, times[i].back() - times[i].front() + 1)); 
	}
	
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < times[i].size(); ++j){
            if(j > k) break;
			for(int i2 = j; i2 < times[i].size(); ++i2){
				int cost = times[i].size() - i2 - 1; 
                if(cost + j > k) continue;
				dp[i][cost+j] = min(dp[i][cost + j], times[i][i2] - times[i][j] + 1); 
			}
            if(times[i].size() <= k) dp[i][times[i].size()] = 0;
		}
	}

	for(int i = 0; i < k+1; ++i){
		ans[0][i] = dp[0][i]; 
	}
	for(int i = 1; i < n; ++i){
		for(int j = 0; j < k + 1; j++){
			for(int j2 = 0; j2 < k + 1 - j; ++j2){
                //cout << i << " " << j << " " << j2 << " " << ans[i-1][j] << " " << dp[i][j2] << "\n";
				ans[i][j2 + j] = min(ans[i][j2 + j], ans[i-1][j] + dp[i][j2]); 
			}
		}
	}
	
    int anss = 1e9;
	for(int i = 0; i < k+1; ++i){
		anss = min(anss, ans[n-1][i]);
	}

	cout << anss << "\n";
	
	

    

    return 0;
}