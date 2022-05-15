/*
ccc96s1
wip
*/

#include <cstdio>

int main(){
    int tc; scanf("%d", &tc);

    while(tc--){
        int n; scanf("%d", &n); 
        int sdiv = 0; 
        for(int i = 1; i < n; i++) if(n % i==0) sdiv+=i; 

        if(sdiv == n){
            printf("%d is a perfect number.\n", n);
        }
        else if(sdiv < n) printf("%d is a deficient number.\n", n);
        else printf("%d is an abundant number.\n", n); 
    }
    return 0;
}