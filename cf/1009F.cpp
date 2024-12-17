/*
1009F
AC, used editorial, a bit wonky
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

vector<vector<int>> g;
vector<int> p, ans;  
struct vertexInfo{
    vector<int>* a; 
    int curMax = 0;
    
    int sz(){
        return (a == nullptr) ? 0 : a->size(); 
    }

    void add(int i, int val){
        (*a)[i] += val; 
        if((i >= curMax && (*a)[i] == (*a)[curMax]) || ((*a)[i] > (*a)[curMax])) curMax = i;
    }
};
vector<vertexInfo> vInfo;

vertexInfo up(int v){
    vertexInfo a = vInfo[v]; 
    if(a.sz() == 0){
        a.a = new vector<int>(1, 1);
        a.curMax = 0;

    }
    else{
        a.a->push_back(0);
        a.add(a.sz() - 1, 1);
    }
    return a;
}

vertexInfo merge(int u, int v){
    vertexInfo a = vInfo[u], b = vInfo[v];

    if(a.sz() < b.sz()) swap(a, b); 

    int as = a.sz();
    int bs = b.sz();

    for(int i = 0; i < b.sz(); ++i){
        a.add(as - i - 1, (*b.a)[bs-i-1]);
    }
    return a; 
}

void solve(int u){
    for(int v : g[u]){
        if(v != p[u]){
            p[v] = u; 
            solve(v);
            vInfo[u] = merge(u, v);
        }
    }
    vInfo[u] = up(u); //add a 1
    ans[u] = vInfo[u].sz() - vInfo[u].curMax -1;
}
int main(){
    int n; cin >> n; 
    g = vector<vector<int>>(n);
    p = ans =  vector<int>(n, 0);
    vInfo = vector<vertexInfo>(n);
    for(int i = 0; i < n-1; ++i){
        int u, v; cin >> u >> v; 
        --u, --v; 
        g[v].push_back(u);
        g[u].push_back(v);
    } 
    
    
    solve(0);

    for(int i = 0; i < n; ++i){
        if(i) cout << " "; 
        cout << ans[i]; 
    }
    cout << "\n";
    return 0;
}