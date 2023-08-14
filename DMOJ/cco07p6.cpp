/*
cco 07 p6 : road construction
ray
AC holy poggers my first 20 pointer
*/ 

#include <cstdio>
#include <vector>
#include <cstring>
using namespace std; 

//enough coding for one day
#define min(a, b) ((a < b) ? a: b)
vector<int> adjl[1001]; 
int dfsn[1001], dfsl[1001], dfsc = 0, ans = 0, dfsp[1001], av[1001], cd[1001], dfsr, rc;

void dfs(int u){
    dfsn[u] = dfsl[u] = dfsc++;
    for(auto it = adjl[u].begin(); it!= adjl[u].end(); it++){
        if(dfsn[*it] == -1){
            dfsp[*it] = u; 
            if(u == dfsr) rc++;

            dfs(*it); 
            

            dfsl[u] = min(dfsl[u], dfsl[*it]);
            
            if(dfsl[*it] > dfsn[u]){
                av[u] = 1; 
            }

            
        }
        else if(dfsp[u] != *it) dfsl[u] = min(dfsn[*it], dfsl[u]);
    }

}

int main(){
    int n, r; scanf("%d %d", &n, &r);
    while(r--){
        int a, b; scanf("%d %d", &a, &b);
        adjl[a].push_back(b); 
        adjl[b].push_back(a); 
    }

    memset(dfsn, -1, sizeof(dfsn));
    for(int i = 1; i <= n; i++){
        if(dfsn[i] == -1){
            dfsr= i; rc = 0; 
            dfs(i);
            av[i] = (rc >1); 
        }
        if(av[i]){
            for(int j : adjl[i]){
                if(dfsl[j] > dfsn[i] && !av[j]){ ans++; }
            }
        }

    }

    int out = ans/2; 
    if(ans%2) out++; 
    
    printf("%d", out);
    return 0;
}