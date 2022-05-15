/*
ccc 04 s5
ac -wacky graph dp
*/

#include <cstdio>
#include <algorithm>

using namespace std; 

int main(){
    int m, n; 

    while(scanf("%d %d", &m, &n), m > 0 ){
        char grid[105][105]; int dp[105][105][3] = {}; //left, down, up 
        for(int i = m-1; i >=0; i--){
            for(int j = 0; j < n; j++){
                scanf(" %c", &grid[i][j]); 
                if(grid[i][j] == '*'){for(int k = 0; k < 3; k++) dp[i][j][k] = -1e9;} // unreachable
                if(grid[i][j] == '.') grid[i][j] = '0';
                //dp[i][j] = -1;
            }
        }
        //debugging
        /*
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '0') printf("."); 
                else printf("%c", grid[i][j]); 
            }
            printf("\n");
        }
        */
        dp[0][0][0] = grid[0][0]-'0';
        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                if(grid[i][j] == '*') continue;
                int val = grid[i][j] - '0';
                if(j > 0 && grid[i][j-1] != '*'){ // all values for j-1 should have been computed by now
                    dp[i][j][0] = val + max(dp[i][j-1][0], max(dp[i][j-1][1], dp[i][j-1][2]));
                }
                else if(i || j) dp[i][j][0] = -1e9;
                 
            }
            for(int i = 0; i < m; i++){
                if(grid[i][j] == '*') continue;
                int val = grid[i][j] - '0';
                if(i >0 && grid[i-1][j] != '*'){//if reachable from above
                    dp[i][j][1] = val + max(dp[i-1][j][1], dp[i-1][j][0]); // max value visiting from right or above (can't come from below);
                }
                else dp[i][j][1] = -1e9; //unreachable from above
            }
            for(int i = m-1; i >= 0; i--){
                if(grid[i][j] == '*') continue;
                int val = grid[i][j] - '0';
                if(i < m-1 && grid[i+1][j] != '*'){
                    dp[i][j][2] = val + max(dp[i+1][j][2], dp[i+1][j][0]);
                } 
                else dp[i][j][2] = -1e9; //unreachable from below
            }
        }
        
        /*
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                printf("%d ", max(dp[i][j][0], max(dp[i][j][1], dp[i][j][2])));
            }
            printf("\n");
        }
        */
        printf("%d\n", max(max(dp[0][n-1][0], dp[0][n-1][1]), dp[0][n-1][2]));
        /*
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++) printf("%d ", max(max(dp[i][j][0], dp[i][j][1]), dp[i][j][2]));
            printf("\n");
        }
        */
    }
    return 0;
}