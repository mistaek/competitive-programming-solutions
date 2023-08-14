/*
dmopc17c1p4
wip - do later, cf round now lol 
*/

#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std; 
long long n, h; 
//can you skip an npc? (1 to 3 rather than 1 to 2 to 3)
//v, c

pair<long long, long long> vis[5005], quest[5005];
long long dp[5005][5005];

long long pick(int npc, int time ){
    //printf("Visiting %d with %d left\n", npc, time);
    if(time < 0) return -1e15;
    if(npc == n) return 0;
    if(time == 0) return dp[npc][time] = 0;
    if(dp[npc][time] != -1) return dp[npc][time];

    dp[npc][time] = max(dp[npc][time], quest[npc].first + pick(npc, time- quest[npc].second)); 
    if(npc < n-1) dp[npc][time] = max(dp[npc][time], vis[npc+1].first + pick(npc+1, time - vis[npc+1].second));

    return dp[npc][time];


}

int main(){
    scanf("%d %d", &n, &h);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld %lld %lld", &vis[i].first, &vis[i].second, &quest[i].first, &quest[i].second);
        //printf("Visiting %d gives %d takes %d, quest gives %d takes %d\n", i, vis[i].first, vis[i].second, quest[i].first, quest[i].second);
    }

    memset(dp, -1, sizeof(dp));

    printf("%lld\n", pick(0, h));
    //printf("%d %d %d %d %d\n", dp[2][0], dp[2][2],  dp[2][4], dp[1][5], dp[0][6]);

    return 0;
}