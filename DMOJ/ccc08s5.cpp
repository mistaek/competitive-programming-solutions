/*
ccc08s5
wip
*/

//WHAT WILL HE SAY

#include <cstdio>
#include <cstring>

int dp[31][31][31][31] = {}, strt[4];

int moves[5][4] = {{2, 1, 0, 2}, {1, 1, 1, 1}, {0, 0, 2, 1}, {0, 3, 0, 0}, {1, 0, 0, 1}};
//working, need to fix up transition

bool lost(int a, int b, int c, int d){
    if(a < 0 || b < 0 || c < 0|| d < 0) return false;
    else return !dp[a][b][c][d]; 

}
   


int main(){
    int tc; scanf("%d", &tc); 
    for(int i = 0; i < 31; i++ ){
            for(int j = 0; j < 31; j++){
                for(int k = 0; k < 31; k++){
                    for(int l = 0; l < 31; l++){
                        for(int m = 0; m < 5; m++){
                            if(lost(i - moves[m][0], j - moves[m][1], k - moves[m][2], l- moves[m][3])) dp[i][j][k][l] = 1 ;
                        }
                    }
                }
            }
        }
    while(tc--){
        //memset(dp, -1, sizeof(dp));
        for(int i = 0; i < 4; i++) scanf("%d", &strt[i]);
        if(dp[strt[0]][strt[1]][strt[2]][strt[3]]) printf("Patrick\n"); 
        else printf("Roland\n");
        

    }
    return 0;
}