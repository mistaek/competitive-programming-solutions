/*
UVa 796 
Ray 
AC
*/


//ill do rest tmrw, idk why it isnt working
#include <cstdio>
#include <vector> 
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)

using namespace std; 

int dfsn[100], dfsl[100], dfsc = 0, dfsp[100], ans = 0;
vector<int> adjl[100]; 
vector<pair<int, int>> out;

bool nfirst = false; 
void dfs(int u){
    dfsn[u] = dfsl[u] = dfsc++;

    for(auto it = adjl[u].begin(); it!= adjl[u].end(); it++){
        if(dfsn[*it] == -1){
            dfsp[*it] = u;

            dfs(*it);

            if(dfsl[*it] > dfsn[u]){
                out.push_back(make_pair(min(u, *it), max(u, *it)));
            }

            dfsl[u] = min(dfsl[u], dfsl[*it]);

        }
        else if(dfsp[u] != *it){
            dfsl[u] = min(dfsl[u], dfsn[*it]);
        }
    }
}
int main(){
    int n; 
    /*
    bruh the stupid () messes up the input so bad
    remove!!!
    meanie bean
    meanie bean
    meanie bean
    meanie bean

    this problem's input is harder than the problem
    */
    while(scanf("%d\n", &n)!= EOF){
		nfirst = true; 
        for(int i = 0; i < 100; i++) adjl[i].clear();
        memset(dfsn, -1, sizeof(dfsn)); memset(dfsl, 0, sizeof(dfsl)); memset(dfsp, 0, sizeof(dfsp)); ans = 0; dfsc=0;
        out.clear(); //forgot!

        int a, b, c; 

        for(int i = 0; i < n; i++){
            scanf("%d (%d)", &a, &c);
            while(c--){
                scanf(" %d", &b);
                adjl[a].push_back(b);
                adjl[b].push_back(a);
            }
        }   
        
        for(int i = 0; i < n; i++){
            if(dfsn[i] == -1){ dfs(i); }
        }
        printf("%d critical links\n", (int)out.size()); 
        
        sort(out.begin(), out.end());

        for(int i = 0; i < (int)out.size(); i++){
           printf("%d - %d\n", out[i].first, out[i].second);
        }
        printf("\n");

    }

    return 0;
}