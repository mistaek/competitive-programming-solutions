/*
ccc 12 s5 
ray 
ac
*/
#include <cstdio>


int r, c, ans; 

int g[26][26];
int main(){
    scanf("%d %d", &r, &c); 
    int k; scanf("%d", &k);
    while(k--){
        int a, b; scanf("%d %d", &a, &b); 
        g[a][b] = -1; //cat
    }
    
    g[r][c] = 1;
    for(int i = r; i >= 1; i--){
        for(int j = c; j >= 1; j--){
            if(g[i][j] != -1){
            if(j +1 <= c){
                if(g[i][j+1] != -1) g[i][j] += g[i][j+1]; 
            }
            if(i +1 <= r){
                if(g[i+1][j] != -1) g[i][j] += g[i+1][j];
            }
            }
        }
    }

    printf("%d", g[1][1]);
    return 0;
}