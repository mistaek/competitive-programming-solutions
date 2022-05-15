/*
ccc 07s3
ac - probably illegal
*/
#include <cstdio>
#include <cstring>
//numbers small again, pretty sure spam traverse passes
int adj[10000], reached[10000];
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, b; 
        scanf("%d %d", &a, &b); adj[a] = b;
    }
    int a, b; 
    while(scanf("%d %d", &a, &b), a){
        int travel = a;
        memset(reached, -1, sizeof(reached)); // slightly faster than 10k
        while(reached[adj[travel]] == -1){ //max 10k operations per traverse
            reached[adj[travel]] = reached[travel] + 1; 
            travel = adj[travel];
        }
        if(reached[b] != -1) printf("Yes %d\n", reached[b]);
        else printf("No\n"); 
    }
    //this solution should be illegal lol
    return 0;
}