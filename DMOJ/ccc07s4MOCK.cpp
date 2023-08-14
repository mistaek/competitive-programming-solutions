/*
ccc 07s4 mock
already did this question :/ - ac
*/
#include <cstdio>
#include <vector>

using namespace std; 
vector<int> adj[11000]; int ways[11001] = {};
int main(){
    int n; scanf("%d", &n);
    int a, b; 
    while(scanf("%d %d", &a, &b), a){
        adj[a].push_back(b);
    }
    ways[n] = 1;
    for(int i = n; i >= 1; i--){
        for(int u : adj[i]) ways[i] += ways[u];
    }
    printf("%d\n", ways[1]);
    return 0;
}