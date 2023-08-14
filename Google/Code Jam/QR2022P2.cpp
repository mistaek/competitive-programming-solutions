/*
QR2022P2
ac
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    for(int tc = 1; tc <= t; tc++){
        printf("Case #%d:", tc); 
        long long c[3][4] = {}, d[4] = {1000000, 1000000, 1000000, 1000000}, ans = 1000000, sum = 0;
        for(int i = 0; i< 3;i++){
            for(int j= 0; j < 4; j++){
                scanf("%lld", &c[i][j]);
            }
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                d[i] = min(d[i], c[j][i]);
            }
            sum += d[i]; 
        }
        if( sum < ans) printf(" IMPOSSIBLE\n");
        else{
           for(int i = 0; i < 4; i++){
               if(ans <= 0) printf(" 0"); 
               else{
                printf(" %lld", min(ans, d[i])); 
                ans-= min(ans, d[i]);
               }

           } 
           printf("\n");
        }
        

    }
    return 0;
}