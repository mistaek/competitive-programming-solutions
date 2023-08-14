/*
uva 11396
ray
AC

*/

//bipartite graph question, but my book spoiled it for me lol
//didn't need to think at all
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>
using namespace std; 

int main(){
    int v; 
    while(scanf("%d", &v), v){
        int a, b; 
        vector<int> adjl[v+1]; 
        int color[v+1]; memset(color, -1, sizeof(color));
        while(scanf("%d %d", &a, &b), a ){
            adjl[a].push_back(b); 
            adjl[b].push_back(a);
        }
        bool yes = true; 
        queue<int> q; 
        color[1] = 1; 
        q.push(1); 
        while(!q.empty() && yes){
            int ind = q.front(); q.pop(); 
            for(auto it = adjl[ind].begin(); it!= adjl[ind].end(); it++){
                if(color[*it] == -1){
                    color[*it] = 1-color[ind]; 
                    q.push(*it); 
                }
                else if(color[*it] == color[ind]){
                    yes = false; 
                    break;
                }
            }

        }
        if(yes) printf("YES\n"); 
        else printf("NO\n"); 
    
    } 
    return 0; 
}
