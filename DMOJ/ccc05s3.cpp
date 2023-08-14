/*
ccc05s3
ac - watch 4 typos
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int p[1100][1100], cur[1100][1100], nxt[1100][1100], n, pr=1, pc = 1;
int maxrs = -1e9, minrs = 1e9, maxcs = -1e9, mincs = 1e9,maxe = -1e9, mine = 1e9;


int main(){
    scanf("%d", &n);
    p[0][0] = 1;
    for(int t = 0; t < n; t++){
        int r, c; scanf("%d %d", &r, &c);
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++) scanf("%d", &cur[i][j]);
        }
        for(int i = 0; i < pr; i++){
            for(int j = 0; j < pc; j++){
                
                for(int k = 0; k < r; k++){
                    for(int l = 0; l < c; l++){
                        nxt[(i*r) + k][(j*c) + l] = p[i][j] * cur[k][l];
                    }
                }
            }
        }
        swap(p, nxt);
        pr *= r; pc *= c;
    }
    for(int i = 0; i < pr; i++){
        int rs = 0;
        for(int j = 0; j < pc; j++){
            rs += p[i][j]; 
            
            maxe = max(maxe, p[i][j]); 
            mine = min(mine, p[i][j]);
        }
        maxrs = max(rs, maxrs); 
        minrs = min(rs, minrs);
    }
    for(int j = 0; j < pc; j++){
        int cs = 0;
        for(int i = 0; i < pr; i++){
            cs += p[i][j]; 
        }
        mincs = min(cs, mincs); 
        maxcs = max(cs, maxcs);
    }
    printf("%d\n%d\n%d\n%d\n%d\n%d\n", maxe, mine, maxrs,minrs,maxcs,mincs);
    
    return 0;  
}