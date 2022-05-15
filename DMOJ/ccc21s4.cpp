/*
ccc 21 s4
wip - currently tles
*/
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
#include <cstring>
using namespace std; 

int n, w, d; 
vector<int> adj[200001];
int seq[200001], dist[200001], p[200001];

void travel(int station, int minute){
    if(minute > n) return; 
    if(dist[station] == -1) dist[station] = minute; //if this is earliest 
    else{
        if(dist[station] > minute) dist[station] = minute; 
        else return;
    }
    int train = seq[minute]; //train is at nth station currently
    for(int v : adj[station]){
        if(dist[v] > minute +1 || dist[v] == -1) travel(v, minute+1); //use walkway
    }
    if(p[station] - p[train] >= 0) travel(seq[p[station] + 1], minute + p[station] - p[train] +1);//will take some time for train to catch up or whatever
}

int main(){
    scanf("%d %d %d", &n, &w, &d); 
    for(int i = 0; i < w; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &seq[i]); 
        p[seq[i]]= i;

    }
    
    for(int i = 0; i < d; i++){
        int n1, n2; scanf("%d %d", &n1, &n2);
        n1--; n2--; //eggs dee 0 based indexing
        if(n1 > n2) swap(n1, n2);
        swap(seq[n1], seq[n2]);
        //for(int j = 0; j < n; j++) printf("%d ", seq[j]); 
        //printf("\n");
        
        swap(p[seq[n1]], p[seq[n2]]);
        //for(int j = 1; j <= n; j++) printf("%d ", p[j]); 
        //printf("\n");
    
        memset(dist, -1, sizeof(dist));
        travel(1, 0);
        printf("%d\n", dist[n]);
    }
    
    return 0;
}