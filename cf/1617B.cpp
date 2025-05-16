/*
1617B
ac
*/

#include <cstdio>

int main(){
    int t; scanf("%d\n", &t); 
    while(t--){
        int n; scanf("%d", &n);
        if(n % 2 == 0) printf("%d %d %d\n", 2, n-3, 1);
        else{
            if((n-1) % 4){
                printf("%d %d %d\n", ((n-1)/2) - 2, ((n-1)/2) + 2, 1); 
            }
            else printf("%d %d %d\n", ((n-1)/2) + 1, ((n-1)/2   ) - 1, 1);
        }
    }
    return 0;
}