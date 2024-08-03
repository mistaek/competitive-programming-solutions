/*
1944B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        int a[2*n] = {}, cnt[n+1] = {}; 
        for(int i = 0; i < 2*n; ++i){
            cin >> a[i]; 
            if(i < n) cnt[a[i]]++; 
        }
        vector<int> singles, left, right; 
        for(int i = 1; i <= n; ++i){
            if(cnt[i] == 1) singles.push_back(i); 
            else if(cnt[i] == 0) right.push_back(i); 
            else left.push_back(i);
        }
        vector<int> oleft, oright; 
        for(int i = 0; i < singles.size() - (singles.size() % 2); ++i){
            oleft.push_back(singles[i]); oright.push_back(singles[i]); 
        }
        int idx = 0; 
        while(oleft.size() < 2*k){
            oleft.push_back(left[idx]);
            oleft.push_back(left[idx]); 
            ++idx; 
        }
        idx = 0; 
        while(oright.size() < 2*k){
            oright.push_back(right[idx]);
            oright.push_back(right[idx]); 
            ++idx; 
        }
        for(int i = 0; i< 2*k; ++i){
            if(i) cout << " "; 
            cout << oleft[i]; 
        }
        
        cout << "\n";
        for(int i = 0; i< 2*k; ++i){
            if(i) cout << " "; 
            cout << oright[i]; 
        }
        cout << "\n";

    }
    return 0;
}