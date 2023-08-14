/*
QR2022P1
ac
*/

#include <cstdio>

int main(){    
    int t; scanf("%d", &t); 
    for(int tc = 1; tc <= t; tc++){
        printf("Case #%d:\n", tc);

        int r, c; scanf("%d %d", &r, &c); 

        for(int i = 0; i < (2*c)+1; i++){
            if(i < 2) printf(".");
            else if(i % 2 == 0) printf("+"); 
            else printf("-");
        }
        printf("\n");
        for(int i = 0; i < (2*c)+1; i++){
            if(i < 2) printf(".");
            else if(i % 2 == 0) printf("|"); 
            else printf(".");
        }
        printf("\n");
        for(int i = 2; i < (2 * r)+1; i++){
            if(i % 2 == 0){
                for(int j = 0; j < (2 *c)+ 1; j++){
                    if(j % 2 == 0) printf("+"); 
                    else printf("-");
                }
            }
            else {
               for(int j = 0; j < (2 *c)+ 1; j++){
                    if(j % 2 == 0) printf("|"); 
                    else printf(".");
                } 
            }
            printf("\n");
        }
    }

    return 0;
}