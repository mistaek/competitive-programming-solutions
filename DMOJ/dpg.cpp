/*
dpg
ray
wip
*/

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std; 

int memo[100005], best = 0;
vector<int> adjl[100005];

int vis(int v){
    if(memo[v] != -1) return memo[v];

    int b=0;
    for(int u : adjl[v]){
        b = max(b, vis(u) +1);
    }

    return memo[v] = b;
}
int main(){
    int m, n; scanf("%d %d", &n, &m);
    memset(memo, -1, sizeof(memo));
    for(int i =0; i < m; i++){
        int a, b; scanf(" %d %d", &a, &b);
        adjl[a].push_back(b);
    }
    
    for(int i = 1; i<= n; i++) best = max(best, vis(i));

    printf("%d\n", best);
    return 0;  
}