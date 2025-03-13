/*
2056B
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        //vector<vector<int>> g(n, vector<int>(n, 0)); 
        vector<set<int>> after(n); //
        vector<int> vis(n, 0); 
        for(int i = 0 ; i < n; ++i){
            for(int j = 0; j < n; ++j){
                char c; cin >> c; 
                if(i == j) continue; 
                if(c == '0'){
                    if(i < j) after[i].insert(j); //i comes after j 
                }
                else if(c == '1') {
                    //there is edge between j and i
                    if(j < i) after[i].insert(j);
                }
            }
        }
        
        /*for(int i = 0; i < n; ++i){
            for(auto& num : after[i]) cout << num << " "; 
            cout << "\n";
        }*/

        for(int i = 0; i < n; ++i){
            int cur = -1; 
            for(int j = 0; j < n; ++j){
                if(!vis[j] && after[j].size() == 0){
                    vis[j] = 1; 
                    cur = j; 
                    if(i) cout << " "; 
                    cout << j + 1; 
                    break; 
                }
            }

            for(int j = 0; j < n; ++j){
                after[j].erase(cur); 
            }
        }
        cout << "\n";
    }
    return 0;
}