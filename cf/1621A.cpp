/*
1621A
WIP
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n, k; scanf("%d %d", &n, &k); 
        char bd[n][n]; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(k > 0 && i == j && (i % 2) == 0){
                    bd[i][j] = 'R'; 
                    k--;
                }
                else bd[i][j] = '.'; 
            }
        }
        if(k > 0) printf("-1\n"); 
        else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    printf("%c", bd[i][j]); 
                }
                printf("\n");
            }
        }
    }
    return 0;
}