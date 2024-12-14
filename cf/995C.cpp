/*
995C
AC : )
*/

#include <iostream>
#include <vector>
#include <set>
#include <cmath>
using namespace std; 

vector<vector<int>> g; 
vector<int> indeg, ans; 
set<pair<int, pair<long long, long long>>> r, l; 

void merge(set<pair<int, pair<long long, long long>>>& s){
    if(s.size() <= 1) return; 
    auto [i, c1] = *s.begin(); 
    auto [j, c2] = *next(s.begin()); 
    s.erase(s.begin()); s.erase(s.begin()); //erase these two vectors

    long long x = c1.first - c2.first, y = c1.second - c2.second; 
    if(y < 0){
        x = -x; y = -y; swap(i, j);
    }

    g[i].push_back(j); 
    indeg[j]++; 

    if(x > 0) r.insert({i, {x, y}}); 
    else l.insert({i, {x, y}}); 
}

double norm(long long x, long long y){
    return sqrt(x * x + y * y); 
}

void dfs(int i, int cur){
    ans[i] *= cur; 
    for(auto v : g[i]) dfs(v, -cur);
}

int main(){

    int n; cin >> n; 
    g = vector<vector<int>>(n);  
    indeg = vector<int>(n, 0), ans = vector<int>(n, 0);
    for(int i = 0; i < n; ++i){
        long long x, y; cin >> x >> y; 
        ans[i] = 1;
        if(y < 0){
            x = -x; y = -y; 
            ans[i] = -1; 
        }
        if(x > 0) r.insert({i, {x, y}}); 
        else l.insert({i, {x, y}}); 
    }

    while(r.size() > 1 || l.size() > 1){
        merge(r); merge(l);
    }

    if(r.size() == 1 && l.size() == 1){
        auto [i, c1] = *r.begin(); 
        auto [j, c2] = *l.begin();

        long long x = c1.first + c2.first, y = c1.second + c2.second;
        if(norm(x, y) > 1500000){
            g[i].push_back(j); 
            indeg[j]++;
        }
    }


    for(int i = 0; i < n; ++i){
        if(indeg[i] == 0) dfs(i, 1); 
    }

    for(int i = 0; i < n; ++i){
        if(i) cout << " "; 
        cout << ans[i]; 
    }
    cout << "\n";

    return 0;
}