/*
uva 455
ac - how to use kmp?
*/

#include <cstdio>
#include <cstring>

int main(){
    int tc; scanf("%d\n\n", &tc); 
    while(tc--){
        char S[80];
        scanf("%s\n\n", S); 
        int l = strlen(S);
        for(int i = 1; i <= l; i++){
            if(l % i) continue; 
            else{
                int j;
                for(j = 0; j < l; j++){
                    if(j + i < l && S[j] != S[j+i]) break; 
                }
                if(j == l){ 
                    printf("%d\n", i); 
                    break;
                }
            }
        }
        if(tc) printf("\n");
    }
    return 0;
}