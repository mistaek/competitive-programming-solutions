/*
UVa 10004
Ray
Probably AC, waiting on verdict.
*/

#include <cstdio>
#include <vector> 
#include <queue>
#include <cstring>

using namespace std; 


int main(){
    int n, e;
    while(scanf("%d", &n), n){
        scanf("%d", &e);
        vector<int> adjl[n]; 
        int color[n]; 
        memset(color, -1, sizeof(color));

        for(int i = 0; i < e ;i++){
            int a, b; scanf("%d %d", &a, &b); 
            adjl[a].push_back(b); 
            adjl[b].push_back(a);
        }

        queue<int> q; 
        bool yes = true; 
        q.push(0); 
        color[0] = 1; 
        while(!q.empty() && yes){
            int ind = q.front(); q.pop();
            for(auto it = adjl[ind].begin(); it!= adjl[ind].end(); it++){
                if(color[*it] == -1){
                    q.push(*it); 
                    color[*it] = 1-color[ind]; 
                }
                else if(color[*it] == color[ind]) {
                    yes = false; 
                    break;
                }  
            }
        }
        if(yes) printf("BICOLORABLE.\n"); 
        else printf("NOT BICOLORABLE.\n");

    }
    return 0;
}