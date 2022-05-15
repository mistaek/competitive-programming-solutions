/*
UVa 247
Ray 
WIP (Almost AC, but missing something too lazy to fix)
*/

#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std; 
//dunno why it no work :(
    //screw this 
    //reea :(())
int dfsl[26], dfsn[26], dfsc; 
bool vis[26]; 
vector<int> adjl[26];
map<string, int> nodes; 

vector<string> out, names;

#define min(a, b) ((a < b) ? a : b)
void dfs(int u){
    dfsl[u] = dfsn[u] = dfsc++;
    out.push_back(names[u]);
    vis[u] = 1;     

    for(auto it = adjl[u].begin(); it!= adjl[u].end(); it++){
        if(dfsn[*it] == -1) dfs(*it);
        if(vis[*it]) dfsl[u] = min(dfsl[u], dfsl[*it]);
    }

    if(dfsn[u] == dfsl[u]){
    bool first = true; 
    while(!out.empty()){
        string s = out.back();
        vis[nodes[s]] = false; 
        out.pop_back();
        if(first){ cout << s; first = false;}
        else cout << ", " << s; 
        if(nodes[s] == u){
            printf("\n");
            break;
        } 
    }
    }
}
int main(){

    int n, m, set = 0; 
    while(scanf("%d %d",&n, &m), n){
        printf("Calling circles for data set %d:\n", ++set);

        dfsc = 0;
        for(int i = 0; i < 26; i++) adjl[i].clear();
        memset(dfsn, -1, sizeof(dfsn)); memset(dfsl, 0, sizeof(dfsl)); memset(vis, false, sizeof(vis)); nodes.clear(); out.clear(); names.clear();

        string name1, name2; 
        int mapcount = 0;
        for(int i = 0; i < m; i++){
            cin >> name1 >> name2;
            if(nodes.count(name1) == 0){ 
                nodes[name1] = mapcount++; names.push_back(name1);
    
            }

            if(nodes.count(name2) == 0){
                nodes[name2] = mapcount++; names.push_back(name2);
            }


            adjl[nodes[name1]].push_back(nodes[name2]);
        }
        for(int i = 0; i < n; i++)
            if(dfsn[i] == -1) dfs(i);
        printf("\n");
    }
    return 0;
}