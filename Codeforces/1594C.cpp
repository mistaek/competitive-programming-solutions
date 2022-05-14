/*
1594C
ac
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        char c; scanf(" %c", &c); 
        char str[n+1]; int d = 0; 
        for(int i = 1; i <= n; i++){
            scanf(" %c", &str[i]); if(str[i] != c) d++; 
        }
        if(d == 0) printf("%d\n", 0); 
        else{
            bool t = true; 
            for(int i = n; i > n/2; i--){
                if(str[i] == c){
                    printf("1\n%d\n", i);
                    t = false; 
                    break; 
                }
            }
            if(t){
                printf("2\n%d %d\n", n, n-1);
            }
        }
    }
    return 0;
}