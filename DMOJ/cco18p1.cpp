/*
cco18p1
ac
*/

#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std; 
int main(){
    int n; scanf("%d", &n);
    pair<char, int> wr[2][n]; 
    for(int i = 0; i < n; i++){
        scanf(" %1c", &wr[0][i].first);
    }
    for(int i = 0; i < n; i++) scanf("%d", &wr[0][i].second); 
    for(int i = 0; i < n; i++) scanf(" %1c", &wr[1][i].first);
    for(int i = 0; i < n; i++) scanf("%d", &wr[1][i].second); 

    int dp[n][n] = {};

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int best = 0; 
            if(i && j) best = dp[i-1][j-1]; 
            if(wr[0][i].first == 'W' && wr[1][j].first == 'L' && (wr[0][i].second > wr[1][j].second)) best+= wr[0][i].second + wr[1][j].second; 
            if(wr[0][i].first == 'L' && wr[1][j].first == 'W' && (wr[0][i].second < wr[1][j].second)) best+= wr[0][i].second + wr[1][j].second; 
            if(i) best = max(best, dp[i-1][j]); 
            if(j) best = max(best, dp[i][j-1]);
            dp[i][j] = best; 
        }
    }

    printf("%d\n", dp[n-1][n-1]);


    return 0;
}