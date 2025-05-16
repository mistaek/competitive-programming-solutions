/*
1582A
WIP
*/
 
#include <cstdio>
#include <algorithm>
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long a, b, c; scanf("%lld %lld %lld", &a, &b, &c); 
        if(c % 2){
            if(b > 0){
                printf("%d\n", 1 - (a % 2));
            }
            else printf("%d\n", a % 3);
        }
        else printf("%d\n", a % 2);
    }
    return 0;
}