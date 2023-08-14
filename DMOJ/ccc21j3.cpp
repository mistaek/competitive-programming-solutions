/*
ccc21j3
ac
*/

#include <cstdio>

int main(){
    int a, b, c, last;
    while(scanf(" %1d%1d%3d", &a, &b, &c)){
        if(a == 9 && b == 9 && c==999) break;
        
        if((a+b) %2) printf("left %d\n", c); 
        else if(a+b == 0 && last %2) printf("left %d\n", c);
        else printf("right %d\n", c);
        last = a+b; 
    }
    return 0;
}