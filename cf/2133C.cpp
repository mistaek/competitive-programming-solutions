/*
2133C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; 
        cin >> n; 
        int maxP = 0; 
        vector<vector<int>> buckets(n+1); 
        for(int i = 1; i <= n; ++i){
            cout << "? " << i << " " << n;
            for(int j = 1; j <= n; ++j) cout << " " << j; 
            cout << endl; 
            int r; cin >> r; 
            maxP = max(r, maxP); 
            buckets[r].push_back(i); 
        }
        vector<int> path; 
        path.push_back(buckets[maxP][0]); 
        while(maxP--){
            if(maxP == 0) break; 
            int cur = path.back(); 
            int l = 0, r = buckets[maxP].size() - 1; 
            while(l < r){
                int mid = (r+l)/2; 
                cout << "? " << cur << " " << (mid - l + 2) << " " << cur;
                for(int i = l; i <= mid; ++i){
                    cout << " " << buckets[maxP][i]; 
                }
                cout << endl; 
                int resp; cin >> resp; 
                if(resp == 2){
                    r = mid; 
                }
                else{
                    l = mid+1; 
                }
            }
            path.push_back(buckets[maxP][l]); 
        }
        cout << "! " << path.size();
        for(auto pp : path) cout << " " << pp; 
        cout << endl; 
    }
    return 0;
}