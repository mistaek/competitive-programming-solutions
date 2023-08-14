/*
uva 12442
ray
AC
*/

#include <cstdio>
#include <cstring>
#include <bitset>
using namespace std; 
//spam dfs
bitset<500005> visited;
int g[500005];
int depth[5000005];


int dfs(int i){
    visited[i] = true;
    depth[i] = 0;
    if(!visited[g[i]]) depth[i] +=dfs(g[i]) + 1; 
    visited[i] = false; 
    return depth[i];

}
int main(){
    int TC; 
    scanf("%d", &TC); 
    for(int tc = 1; tc <= TC; tc++){
        int n; scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int s, r; scanf("%d %d", &s, &r); 
            g[s] = r;
        }
        int cur = 0,best = -1, bd = -1; 
        memset(depth, -1, sizeof(depth));
        for(int i = 1; i <= n; i++){
            cur = (depth[i] == -1)? dfs(i) : depth[i];
            if(cur > bd){
                best = i; 
                bd = cur; 
            }
        }

        printf("Case %d: %d\n", tc, best); 
        
    }
    return 0;
}