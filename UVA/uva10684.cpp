/*
UVa 10684 The Jackpot
[NAME]
WIP
*/

//maximum 1d sum
#include <cstdio>


#define max(a, b) ((a < b) ? b : a)

int main(){
    int length; 
    while(scanf("%d", &length), length){
        int seq[length];
        for(int i = 0; i < length; i++){
            scanf("%d", &seq[i]);
        }
        int sum = 0, ans = 0; 
        for(int i = 0; i < length; i++){
            sum += seq[i]; 
            ans = max(ans, sum); 
            if (sum < 0) sum = 0; 
        }
        if(ans > 0) printf("The maximum winning streak is %d.\n", ans); 
        else printf("Losing streak.\n");

    }
    return 0; 
}