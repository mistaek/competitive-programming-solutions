/*
CCC '97
[NAME]
WIP
*/

//full of regret

#include <cstdio>

int main(){
    int TC; scanf("%d", &TC); 
    while(TC--){
        int n; 
        scanf("%d", &n); 
        printf("Round 0: %d undefeated, 0 one-loss, 0 eliminated\n", n);
        int undef = n, loss = 0, elim = 0, round = 0;
        while(undef || loss > 1){
            round++; 
            if(undef == 1 && loss == 1){
                //something
                loss = 2; 
                undef = 0; 
                printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", round, undef, loss, elim);
            }
            else{
                int lose = undef/2; 
                int out = loss/2; 
                undef-= lose; 
                loss-=out; 
                elim+=out; 
                loss+= lose; 

                printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", round, undef, loss, elim);

            }
            

        } 
        printf("There are %d rounds.\n\n", round); 

    }
    return 0;
}