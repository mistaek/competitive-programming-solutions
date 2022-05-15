/*
ccc05s2
ac
*/

#include <cstdio>

int main(){
    int c, r; scanf("%d %d", &c, &r);
    int x = 0, y = 0, cx, cy;
    while(scanf("%d %d", &cx, &cy)){
        if(!(cx||cy)) break;
        x += cx; y += cy; if(y < 0) y = 0; if(y>r) y = r; if(x < 0) x = 0; if(x > c) x = c; 
        printf("%d %d\n", x, y);
    }
    return 0;
}