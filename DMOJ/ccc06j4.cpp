/*
ccc06j4
wip
*/

#include <cstdio>
#include <vector>
#include <cstring>


using namespace std; 
vector<int> adj[100]; 
vector<int> toposort; 
int p[100]; 
bool dag = true; 

void dfs1(int u){
    for(int v : adj[u]){
        if(p[v] == -1){
            p[v] = u; 
            dfs1(v);
        }
        if(p[v]!= -1 && p[v] != u){
            dag = false; 
        }
    }
}
void dfs2(int u){
    for(int v : adj[u]){
        if(p[v] == -1){
            p[v] = u; 
            dfs2(v);
        }
    }
    toposort.push_back(u);
}


int main(){
    memset(p, -1, sizeof(p));
    int a, b; 
    adj[1].push_back(7); adj[1].push_back(4); adj[2].push_back(1); adj[3].push_back(4); adj[3].push_back(5);
    while(scanf("%d\n%d", &a, &b), a != 0){
        adj[a].push_back(b);
    }    
    for(int i = 1; i < 8; i++){
        if(p[i] == -1){ 
            dfs1(i); 
        }
    }

    if(!dag){ printf("Cannot complete these tasks. Going to bed.\n"); return 0;}
    memset(p, -1, sizeof(p));
    for(int i = 1; i < 8; i++){
        if(p[i] == -1){ dfs2(i);}
    }

    
    for(int i : toposort) printf("%d ", i);

    return 0;
}