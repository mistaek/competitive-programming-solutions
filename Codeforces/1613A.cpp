/*
CF1613A
AC -don't rely on doubles lol
got hacked kekw 
*/

#include <cstdio>
#include <cmath>

void comp(long long x1, long long p1, long long x2, long long p2){
    while (x1 - x2 >= 9 && p2 > 0){
        x2 *= 10; p2--; 
    }
    while(x2 - x1 >= 9 && p1 > 0){
        x1 *= 10; p1--; 
    }

    if(p1 > p2) printf(">\n");
    else if(p2 > p1) printf("<\n"); 
    else if(x1 < x2) printf("<\n");
    else if(x1 > x2) printf(">\n"); 
    else printf("=\n");
}
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long x1, p1, x2, p2; scanf("%lld %lld %lld %lld", &x1, &p1, &x2, &p2);
        comp(x1, p1, x2, p2); 
    }

    return 0;
}