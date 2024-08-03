/*
963B
*/
 
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <deque>
 
using namespace std; 
 
vector<set<int>> tree;
 
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int n; cin >> n;
    tree = vector<set<int>>(n+1);
    vector<int> d(n+1);
    vector<int> proc(n+1);
    for(int i = 1; i <= n; ++i)
    {
        int pi; cin >> pi; 
        if(pi == 0) continue;
        tree[i].insert(pi);
        tree[pi].insert(i);
    }
    vector<int> out, singleton; 
    queue<int> rm;
    for(int i = 1; i <= n; ++i){
        d[i] = tree[i].size(); 
        if(d[i]== 1 || d[i] == 0) rm.push(i);
    }
 
    bool pos = true; 
    while(!rm.empty()){
        auto u = rm.front(); 
        rm.pop();
        if(proc[u]) continue;
        //cout << u << "\n";
        if(tree[u].size() == 0){
            if(d[u] % 2){
                pos = false;
                break; 
            }
            else{
                out.push_back(u); proc[u] = 1; continue;
            }
        }
        else if(tree[u].size() == 1){
            if(d[u] == 1){ 
                singleton.push_back(u);
                proc[u] = 1; 
                if(tree[u].begin() != tree[u].end()){
                    auto v = *tree[u].begin();
                    tree[v].erase(u);
                    if(tree[v].size() == 0 || tree[v].size() == 1) rm.push(v);
                }
            }
            else if(d[u] % 2 == 0){
                auto v = *tree[u].begin(); 
                tree[*tree[u].begin()].erase(u);
                out.push_back(u); 
                --d[v];
                if(tree[v].size() == 0 || tree[v].size() == 1) rm.push(v);
                proc[u] = 1; 
            } 
        }
    }
 
    if(pos && (out.size() + singleton.size() == n)){
        cout << "YES\n";
        for(auto v : out) cout << v << "\n";
        for(auto v: singleton) cout << v << "\n";
    }
    else cout << "NO\n";
 
    return 0;
}