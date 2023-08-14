/*
cco10p4
ac - watch the variable exit conditions.
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std; 

int t, n, b;
vector<pair<int, int>> parts[6];

int dp[6][3005]; //max value at type n with remaining b 

int pick(int typ, int remw){

    if(remw < 0 ){ 
        //printf("On type %d with remw %d\n", typ, remw); 
    return -1e9; }
    if(typ == t+1) return 0;

    if(dp[typ][remw] != -1 ) return dp[typ][remw];

    for(pair<int, int> part : parts[typ]){
        //printf("Inspecting %d %d for part %d, will leave %d, currently dp is %d\n", part.first, part.second, typ, remw-part.first, dp[typ][remw]);
        //c, v; 
        
        dp[typ][remw] = max(dp[typ][remw], part.second + pick(typ+1, remw - part.first));
        //printf("compared with pick(%d, %d - %d) = %d\n", typ+1, remw, part.first, pick(typ+1, remw - part.first));
    }

    if(dp[typ][remw] == -1) return -1e9;
    return dp[typ][remw];

}


int main(){
    scanf("%d %d", &t, &n);
    for(int i = 0; i < n; i++){
        int c, v, typee; scanf("%d %d %d", &c, &v, &typee);
        parts[typee].push_back({c, v});
    }
    scanf("%d", &b); 
    memset(dp, -1, sizeof(dp));
    pick(1, b);
    printf("%d\n", dp[1][b]);
    return 0;
}