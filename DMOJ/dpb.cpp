/*
Frog 2
[NAME]
AC
*/

#include <cstdio>
#include <cstring>

#define min(a, b) ((a < b) ? a : b)

int abs(int a){
    if(a > 0) return a; 
    else return -a; 
}
int main(){
    int n, k; scanf("%d %d", &n, &k);
    int rocks[n], memo[n];
    memset(memo, -1, sizeof(memo));

    for(int i = 0; i < n; i++) scanf("%d", &rocks[i]);
    memo[0] = 0; 
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            if(i >= j){
                if(j == 1) memo[i] = memo[i-1] + abs(rocks[i] - rocks[i-1]); 
                else memo[i] = min(memo[i], memo[i-j] + abs(rocks[i] - rocks[i-j]));
            }
            else break; 
        }
    }
    printf("%d\n", memo[n-1]);
    return 0; 
}