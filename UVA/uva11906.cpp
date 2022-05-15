/*
UVa 11906
Ray
WIP
*/

#include <cstdio>


int main(){
    int TC; scanf("%d", &TC) 
    for(int c = 1; c < TC; c++){
        int r, c, m, n; 
        scanf("%d %d %d %d", &r, &c, &m, &n); 
        int field[r][c] = {}; 
        int w; scanf("%d", &w); 
        for(int i = 0; i < w; i++){
            int a, b; scanf("%d %d", &a, &b); 
            field[a][b] = 1; 
        }

        //output
        printf("Case %d: %d %d\n", c)
    }
    return 0; 
}