/*
dpn
ray
wip
*/

#include <cstdio>
#include <vector>
#include <cstring>

typedef unsigned long long ull; 
using namespace std; 
//BASICALLY COPIED SOL FROM ATCODER      DO NOT SUBMIT DO NOT SUBMIT
ull memo[405][405];
ull arr[405], psa[405];

unsigned long long backtrack(int l, int r){
    if(l == r) return memo[l][r] = 0;
    if(memo[l][r] != -1) return memo[l][r]; 

    memo[l][r] = (long long)1e14;
    for(int i = l; i <= r; i++){
    	
        backtrack(l, i); 
        backtrack(i+1, r);
        memo[l][r] = min(memo[l][r],memo[l][i] +  memo[i+1][r] + psa[r] - psa[l-1]);
    }
    return memo[l][r];

}

int main(){
    int n; scanf("%d", &n); 

    for(int i = 1; i <= n; i++){ 
        scanf("%d", &arr[i]);  
        psa[i] = psa[i-1] + arr[i];
    }

    memset(memo, -1, sizeof(memo));

    
    printf("%llu\n", backtrack(1, n));

    return 0;
}