/*
ccc20s2
ac
*/

#include <cstdio>
#include <vector>
#include <queue>

using namespace std; 

vector<long long> adj[1000001];

int main(){
    long long m, n; scanf(" %lld %lld", &m, &n);
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            long long in; scanf(" %lld", &in);
            adj[i*j].push_back(in);
        }
    }
    queue<long long> bfs;
    int vis[1000001] = {}; 
    bfs.push(adj[1][0]);//first number
    vis[1] = 1; vis[adj[1][0]] = 1;
    while(!bfs.empty()){
        long long a = bfs.front(); bfs.pop(); 
        for(long long b : adj[a]){
            if(vis[b] == 0){vis[b] = 1; bfs.push(b);}
        }
    }
    if(vis[m*n]==1) printf("yes\n");
    else printf("no\n");
    return 0;
}