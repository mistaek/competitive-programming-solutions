/*
1889B
AC, prove your solutions if your intuition submit fails
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

using i64 = long long; 

int main(){
    ios::sync_with_stdio(0); 
    cin.tie(0); 

    int t; cin >> t; 
    while(t--){
        i64 n, c; cin >> n >> c; 
        vector<pair<i64, i64>> a(n); 
        
        for(int i = 0; i < n; ++i){
            i64 ai; cin >> ai; 
            a[i] = {ai, i+1}; 
        }
        i64 sum = a[0].first; 
        sort(a.begin(), a.end(), [&](pair<i64, i64> p, pair<i64, i64> q){
            if(p.first - (p.second * c) > q.first - (q.second * c)) return true; 
            else return false; 
        });

        bool ans = true; 
        for(auto p : a){
            //cout << p.first << " " << p.second << "\n";
            if(p.second == 1) continue; 
            else{
                if(sum + p.first >= p.second * c) sum += p.first; 
                else{
                    ans = false; 
                    break; 
                }
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";

    }
    return 0; 
}