/*
UVa 216
[NAME] 
WIP
*/

//look for help
#include <cstdio>
#include <cstring>
#include <cmath>

#define min(a, b) ((a < b) ? a : b)
int ncomps, x[10], y[10]; 
double dist[10][10], memo[10][1 << 10]; 


double tsp(int pos, int mask){
    if(mask == (1 << (ncomps+1)) -1) return 0;  
    if(memo[pos][mask] != -1) return memo[pos][mask];

    double ans = 10000000; 
    int nxt = 0; 
    for(int i = 0; i < ncomps; i++){
        if(i != pos && !(mask & (1 << i))){
            if(dist[pos][i] + tsp(i, mask | (1 << i)) > ans){
                ans = dist[pos][i] + tsp(i, mask | (1 << i)); 
                nxt = i; 
            }
        }
    }
    printf("Cable requirement to connect (%d, %d) to (%d, %d) is %lf feet.", x[pos], y[pos], x[nxt], y[nxt], ans); 
    return memo[pos][mask] = ans; 

}
int main(){
    int c = 1; 
    while(scanf("%d", &ncomps), ncomps){
        for(int i = 0; i < ncomps; i++ ) scanf("%d %d", &x[i], &y[i]);
        printf("**********************************************************\nNetwork %d\n", c);

        for(int i = 0; i < ncomps; i++){
            for(int j = 0; j <ncomps; j++){
                dist[i][j] = (double) sqrt( (x[i] - x[j]) *(x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
            }
        }

        memset(memo, -1, sizeof(memo)); 
        tsp(0, 1);
        
    }    
    return 0; 
}