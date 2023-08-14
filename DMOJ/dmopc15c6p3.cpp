/*
dmopc15c6p3
wip - uses 2 pointer technique!
no clue why it no werk, fix later
*/

#include <cstdio>

#define min(a, b) ((a < b) ? a : b)

int main(){
    long long n, m, k; scanf("%lld %lld %lld", &n, &m, &k);
    long long grid[n], diff[n+1] = {}; 
    for(long long i = 0; i < n; i++) grid[i] = m; 
    for(long long i = 0; i < m; i++){
        long long a, b; scanf("%lld %lld", &a, &b);
        diff[a-1]--; diff[b]++;
    }
    long long change = 0;
    for(int i = 0; i < n; i++){
        change += diff[i]; 
        grid[i] += change; 
        //printf("Row %d has %d potatoes\n", i, grid[i]);
    }  
    //printf("\n");

    long long psa[n] = {}; psa[0] = grid[0]; 
    for(int i = 1; i < n; i++) psa[i] = psa[i-1] + grid[i];

    long long l=0, r= 0, w = 200002;
    while(r < n && l <= r){
        if(psa[r] - psa[l] >= k){
            //printf("Range %d %d works\n", l ,r);
            w = min(w, r- l);
            l++;
        }
        else r++;
    }

    if(k == 0) printf("0\n");
    else if(w == 200002) printf("-1\n");
    else printf("%lld\n", w);

    return 0;
}