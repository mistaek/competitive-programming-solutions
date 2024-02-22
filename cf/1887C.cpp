/*
1887C
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std; 

vector<long long> a, st, upd; 
vector<vector<long long>> q; 
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; 
    while(t--){
        int n; cin >> n; 
        a = vector<long long>(n, 0); 
        st = upd = vector<long long>(2*n, 0);

        for(int i = 0; i < n; i++) cin >> a[i];

        int qn; cin >> qn; 
        q = vector<vector<long long>>(qn+1, vector<long long>(3)); 
        vector<pair<long long, long long>> ss(qn+1);

        set<int> ac; ac.insert(0);
        for(int i =1; i <= qn; i++){ 
            cin >> q[i][0] >> q[i][1] >> q[i][2]; 
            ss[i].first = q[i][0]; 
            ss[i].second = i; 
            ac.insert(i); 
        }

        sort(ss.begin(), ss.end());
        long long cur = 0, idx = 0; 
        pair<int, int> intv = {};
        for(int i = 0; i < qn; i++){

        }



    }
    return 0;
}