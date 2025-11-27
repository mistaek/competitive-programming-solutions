/*
1179A
*/

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    long long n, q; cin >> n >> q;
    deque<int> dq;
    
    vector<pair<int, int>> ans;
    for(int i = 0; i < n; ++i){
        int ai; cin >> ai; 
        dq.push_back(ai);
    }

    for(int i = 0; i < 2*(n-1); ++i){
        auto a = dq.front(); dq.pop_front();
        auto b = dq.front(); dq.pop_front(); 
        ans.push_back({a, b});
        dq.push_back(min(a, b)); 
        dq.push_front(max(a, b));
    }

    for(int i = 0; i < q; ++i){
        long long m; cin >> m; 
        if(m <= n-1){
            cout << ans[m-1].first << " " << ans[m-1].second << "\n";
        }
        else {
            cout << ans[n - 2 + (m % (n-1))].first  << " " << ans[n-2 + (m % (n-1))].second << "\n";
        }
    }
    return 0;
}