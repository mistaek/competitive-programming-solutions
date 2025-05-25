    /*
    2110E
    funky
    */
     
    #include <iostream>
    #include <vector>
    #include <map>
    #include <functional>
    #include <set>
     
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(0); 
        cin.tie(0); 
        int t; cin >> t; 
     
        while(t--){
            int n; cin >> n; 
            map<int, vector<pair<int, int>>> st[2]; 
            vector<bool> vis(n+1, false); 
            for(int i = 0; i < n; ++i){
                int v, p; cin >> v >> p; 
                st[0][v].push_back({p, i+1}); 
                st[1][p].push_back({v, i+1});
            }
            long long numOdd = 0;
            int start = 0, startTurn = 0; 
            for(auto& [k, s] : st[0]){
                if(s.size() % 2){
                    numOdd++; 
                    start = k; 
                    startTurn = 0;
                }
            }
     
            for(auto&[k, s] : st[1]){
                if(s.size() %2){
                    numOdd++; 
                    start = k; 
                    startTurn= 1; 
                }
            }
            if(numOdd > 2LL){
                cout << "NO\n"; 
                continue; 
            }
     
            if(numOdd == 0){
                start = st[0].begin()->first; 
                startTurn= 0;
            }
     
            vector<int> path; 
            function<void(int, int)> dfs = [&](int u, int turn){
                while(!st[turn][u].empty()){
                    auto [v, idx] = st[turn][u].back();  
                    st[turn][u].pop_back();
                    if(vis[idx]) continue;
                    vis[idx] = true; 
                    dfs(v, 1-turn);
                    path.push_back(idx);

                }
            }; 
     
            dfs(start, startTurn); 
     
            /*cout << "GOT HERE\n"; 
            for(int i = 0; i < path.size(); ++i){
                    if(i) cout << " "; 
                    cout << path[i];
                }
                cout << "\n";*/
            if(path.size() != n) cout <<"NO\n"; 
            else{
                cout << "YES\n";                
                for(int i = 0; i < n; ++i){
                    if(i) cout << " "; 
                    cout << path[i]; 
                }
                cout << "\n";
            }
        } 
        return 0;
    }