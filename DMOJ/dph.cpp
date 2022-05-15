/*
dph
ray
ac
*/

#include <cstdio>

#define MOD 1000000007

int main(){
    int h, w; scanf("%d %d", &h, &w);
    char g[h][w] = {}; int m[h][w] = {};
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            scanf(" %1c", &g[i][j]);

        }
    }
    m[h-1][w-1] = 1;
    for(int i = h-1; i >= 0; i--){
        for(int j = w-1; j >= 0; j--){
            if(i == h-1 && j == w-1) continue;
            if(g[i][j] != '#'){
                if(i+1 < h) m[i][j] += (m[i+1][j] % MOD);
                if(j + 1 < w) m[i][j] += (m[i][j+1] % MOD);
                m[i][j] %= MOD;
            }

            
        }
    }
    //for(int i = 0; i < h; i++){for(int j = 0; j < w; j++) printf("%d", m[i][j]);printf("\n");}
    printf("%d\n", m[0][0]);
    return 0;
}