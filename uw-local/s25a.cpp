/*
s25a
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int c; cin >> c;
    while(c--){
        int n, t; cin >> n >> t; 
        long long base = 0;
        vector<vector<vector<int>>> g(n, vector<vector<int>>(2, vector<int>(2))); 
        for(int i = 0; i < n; ++i){
            int p, bb, be, eb, ee; cin >> p >> bb >> be >> eb >> ee; 
            base += p; 
            g[i][0][0] = bb; 
            g[i][0][1] = be; 
            g[i][1][0] = eb; 
            g[i][1][1] = ee; 
        }
        vector<vector<long long>> best(n+1, vector<long long>(2, 1e15)); // fastest time, finish at endpoint 0 or 1 of current hike
        best[0][0] = 0; //walk backwards on 0
        best[0][1] = 0; // walk forwards on 0
        for(int i = 0; i < n; ++i){
            // best time to finish walk of i+1 at endpoint 0 is:
            // walk forwards on i, take road to 1, [i][1] + [i][1][1]
            // walk backwards on i, then take road to 1 [i][0] + [i][0][1]
            best[i+1][0] = min(best[i][1] + g[i][1][1], best[i][0] + g[i][0][1]); 

            best[i+1][1] = min(best[i][1] + g[i][1][0], best[i][0] + g[i][0][0]); 
        }
        if(base + min(best[n][0], best[n][1]) > t){
            cout << "IMPOSSIBLE\n"; 
        }
        else{
            vector<char> ans(n); 
            int cur = (best[n][0] > best[n][1]) ? 1 : 0; // we are at this endpoint at the end
            for(int i = n-1; i >= 0; --i){
                if(best[i+1][cur] == best[i][1] + g[i][1][1-cur]){ // if we got here from the endpoint of previous
                    cur = 1; 
                    ans[i] = 'F';
                }
                else{ // if we got here from beginning of previous
                    cur = 0; 
                    ans[i] = 'B';
                }
            }
            for(auto c : ans) cout << c; 
            cout << "\n";
        }

    
    }
    return 0;
}