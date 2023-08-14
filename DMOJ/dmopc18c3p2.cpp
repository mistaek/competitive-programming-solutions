/*
dmopc18c3p2
ac - basic 
*/

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std; 

int dp[100005][3];
int a[100005], b[100005]; 
int n; 

int backtrack(int word, int chain){
    if(word == n) return 0; 
    if(dp[word][chain] != -1) return dp[word][chain];
    if(chain == 2) return dp[word][chain] = b[word] + backtrack(word+1, 0); 
    else return dp[word][chain] = max(a[word] + backtrack(word+1, chain+1), b[word] + backtrack(word+1, 0));
    
}
int main(){
    scanf("%d", &n); 
    memset(dp, -1, sizeof(dp));
    for(int i = 0; i < n; i++) scanf("%d", &a[i]); 
    for(int i = 0; i < n; i++) scanf("%d", &b[i]); 
    printf("%d\n", backtrack(0, 0));
    return 0;
}