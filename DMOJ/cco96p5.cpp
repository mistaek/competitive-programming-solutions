/*
cco96p5
ac - simple dfs
*/

#include <cstdio>
#include <map>
#include <string>
#include <iostream>
#include <vector> 
using namespace std; 

map<string, int> node; map<int, char> lett;  
vector<int> adjl[10000], out; 

int objective = 0;
bool dfs(int u, int p){
    if(u == objective){ out.push_back(u); return true; }
    bool yes = false; 
    for(int v : adjl[u]){
        if(v != p){
            if(dfs(v, u)) yes = true; 
        }
    }
    if(yes) out.push_back(u);
    return yes; 
}

int main(){
    node["Rome"] = 0; lett[0] = 'R'; 
    int ccount = 1;  
    
    int m, n; scanf("%d %d", &m, &n);
    for(int i = 0; i < m; i++){
        string a, b; 
        cin >> a >> b; 
        if(node.count(a) == 0){ lett[ccount] = a[0]; node[a] = ccount++;}
        if(node.count(b) == 0){ lett[ccount] = b[0]; node[b] = ccount++;}
        adjl[node[a]].push_back(node[b]); adjl[node[b]].push_back(node[a]);
    }
    for(int i = 0; i < n; i++){
        out.clear(); 
        string a, b; cin>> a >> b; 
        //printf("traversing from %s to %s\n", a.c_str(), b.c_str()); 
        objective = node[b]; 
        dfs(node[a], node[a]);
        for(vector<int>::reverse_iterator it = out.rbegin(); it!= out.rend(); it++) printf("%1c", lett[*it]);
        printf("\n");
    }


    return 0;
}