/*
1010D
*/

#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std; 

enum Type{
    AND, 
    OR, 
    XOR, 
    NOT, 
    IN
};

vector<bool> usual; 
vector<set<int>*> flip;
vector<Type> type; 
vector<vector<int>> g; 

set<int>* merge(set<int>* a, set<int>* b){
    if(a == nullptr) return b; 
    if(b == nullptr) return a; 
    if(a->size() < b->size()) swap(a, b); 
    for(auto n : *b) a->insert(n); 
    
    return a; 
}

void dfs(int u){
    if(type[u] == IN) return; 
    if(type[u] == NOT){
        int v = g[u][0]; //should have exactly 1 
        dfs(v); 
        usual[u] = !usual[v];
        flip[u] = flip[v]; 
        return; 
    }

    //always have exactly 2 kids
    int v = g[u][0], w = g[u][1]; 
    dfs(v); dfs(w); 

    if(type[u] == AND){
        usual[u] = usual[v] && usual[w];
        if(usual[u]) flip[u] = merge(flip[v], flip[w]);
        else if(usual[v]) flip[u] = flip[w];
        else if(usual[w]) flip[u] = flip[v]; 
        
    }
    else if(type[u] == OR){
        usual[u] = usual[v] | usual[w]; 
        if(!usual[u]) flip[u] = merge(flip[v], flip[w]);
        else if( usual[v] & !usual[w]) flip[u] = flip[v]; 
        else if(usual[w] & !usual[v]) flip[u] = flip[w]; 
    }
    else if(type[u] == XOR){
        usual[u] = usual[v]^usual[w]; 
        flip[u] = merge(flip[v], flip[w]);
    }

}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int n; cin >> n; 
    usual = vector<bool>(n, false); 
    type = vector<Type>(n); 
    g = vector<vector<int>>(n);
    flip = vector<set<int>*>(n, nullptr);
    vector<int> inputs; 
    for(int i = 0; i < n; ++i){
        string tp; cin >> tp; 
        if(tp == "IN"){
            inputs.push_back(i);
            type[i] = IN; 
            int bit; cin >> bit; 
            usual[i] = bit; 
            flip[i] = new set<int>; 
            flip[i]->insert(i);
        }
        if(tp == "AND" || tp == "OR" || tp == "XOR"){
            if(tp == "AND") type[i] = AND; 
            else if(tp == "OR") type[i] = OR; 
            else type[i] = XOR; 
            int a, b; cin >> a >> b;
            g[i].push_back(--a); g[i].push_back(--b);
        }
        if(tp == "NOT"){
            type[i] = NOT; 
            int a; cin >> a; 
            g[i].push_back(--a); 
            type[i] = NOT; 
        }
    }

    dfs(0);

    for(auto input : inputs){
        bool val = usual[0];
        if(!(flip[0] == nullptr || flip[0]->find(input) == flip[0]->end())) val = !val; 
        cout << ((val) ? 1 : 0);
    }
    cout << "\n";
    return 0;
}