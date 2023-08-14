/*
cco prep 16q1 
Ray
wip
*/

//attempt 1: maximum 2d subarray sum 

#include <cstdio>


int main(){
    int k; scanf("%d", &k); 
    while(k--){
        int m, n; scanf(" %d %d", &m, &n);
        int g[m][n]; char in; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                scanf(" %1c", &in);
                if(in == 'R') g[i][j] = -10000; 
                else g[i][j] = 3; 
            }
        }
    }
    return 0;
}