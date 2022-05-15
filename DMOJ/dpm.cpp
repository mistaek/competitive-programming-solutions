/*
dpm 
ray
AC- make sure your state is correct!
*/

#include <cstdio>
#include <cstring>

typedef long long ull; 
#define MOD 1000000007
ull memo[101][100005];//student, remcandies
ull a[101];
int n, k; 
int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)scanf("%lld", &a[i]);

    memo[0][0] = 1; //1 way to distribute 0 candies among the first 0 persons

    for(int i = 1; i <= n; i++){
        int psa[k+1];
        psa[0] = memo[i-1][0];
        for(int j = 1; j <=k; j++){
            psa[j] = psa[j-1] + memo[i-1][j];
            psa[j] %= MOD;
            psa[j] += MOD; 
            psa[j] %= MOD; 
        }

        for(int j = 0; j<= k; j++){
            memo[i][j] = psa[j] - ((j - a[i] > 0) ? psa[j-a[i]-1] : 0); 
            memo[i][j] %= MOD;
            memo[i][j] += MOD; 
            memo[i][j] %= MOD;
        }
    }
    printf("%llu\n", memo[n][k]);
    
    
    return 0;
}