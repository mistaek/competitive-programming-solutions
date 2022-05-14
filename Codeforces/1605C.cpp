/* 
1605C
AC - missed one case, be more careful!
*/

#include <cstdio>

int main(){
    int t; scanf("%d\n",&t);
    while(t--){
        int n; scanf("%d\n", &n);
        char str[n];
        for(int i = 0; i < n; i++) scanf(" %c", &str[i]);
        bool out = false; 
        for(int i = 1; i < n; i++){
            if(str[i] == 'a' && str[i-1] == 'a'){
                printf("2\n"); 
                out = true; 
                break;
            }
        }
        if(out) continue;
        for(int i = 2; i < n; i++){
            if(str[i] == 'a' && str[i-2] == 'a'){
                printf("3\n"); 
                out = true; break; 
            }
        }
        if(out) continue; 
        for(int i = 3; i < n; i++){
            if(str[i] == 'a' && str[i-3] == 'a' && str[i-1] != str[i-2]){
                printf("4\n"); 
                out = true; break;
            }
        }
        if(out) continue; 
        for(int i = 6; i < n; i++){
            if(str[i] == 'a' && str[i-3] == 'a' && str[i-6] == 'a' && str[i-5] != str[i-1]){
                printf("7\n");
                out = true; break;
            }
        }
        if(out) continue;
        printf("-1\n");
    }
    return 0;
}