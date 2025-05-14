/*
1154G
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 
#include <numeric>

using namespace std; 

int main(){
    iostream::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int n; cin >> n; 
    vector<int> cnt(1e7 + 1, 0); 
    map<int, vector<int>> inds; 
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        cnt[a]++; 
        inds[a].push_back(i+1); 
    }

    long long best = 1e15; 
    pair<int, int> ans = {1, 2}; 
    for(int i = 1; i <= 10000000; ++i){
        int prev = 0; 
        for(int j = i; j <= 10000000; j+=i){
            if(cnt[j] >= 2){
                if(1ll*j < best){
                    best = 1ll*j; 
                    ans = {inds[j][0], inds[j][1]};
                }
                break; 
            }
            else if(cnt[j] == 1){
                if(prev){
                    if(1ll*prev*j/gcd(prev,j) < best){
                        best = 1ll*prev*j/gcd(prev,j); 
                        ans = {inds[prev][0], inds[j][0]};
                    }
                    break; 
                }
                prev = j; 
            }
        }
    }

    if(ans.first > ans.second) swap(ans.first, ans.second); 
    cout << ans.first << " " << ans.second << "\n";
    return 0;
}