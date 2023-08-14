/*
UVa 357 
[NAME]
AC
*/

#include <cstdio>
#include <cstring>

typedef long long ll; 
//figure out bottom up later
ll memo[6][30005], coins[5] = {1, 5, 10, 25, 50}; 

ll change(ll t, ll a){
    if(a == 0) return 1; 
    if(memo[t][a] != -1) return memo[t][a]; 
    if(a < 0 || t == 5) return 0; 
    return memo[t][a] = change(t+1, a) + change(t, a - coins[t]);   
}
int main(){
    ll a;         
    memset(memo, -1, sizeof(memo)); 
    while(scanf("%lld", &a) != EOF){
        if(a < 5){ printf("There is only 1 way to produce %lld cents change.\n", a); continue; }
        else printf("There are %lld ways to produce %lld cents change.\n", change(0, a), a);
    }    
    return 0; 
}