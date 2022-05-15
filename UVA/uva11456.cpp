/*
UVa 11456
[NAME]
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std; 

int main(){
    int TC; scanf("%d", &TC); 
    while(TC--){
        int cars; scanf("%d", &cars); 
        int weights[cars], backwards[cars];
        for(int i = 0; i < cars; i++){
            scanf("%d", &weights[i]); 
            backwards[i] = -weights[i]; 
        
        } 
        int lis = 0, lis2 = 0, max = 0, L[cars+5], L2[cars+5];
        for(int i = 0 ; i < cars; i++){
            int pos = lower_bound(L, L + lis, weights[i]) - L; 
            int pos2 = lower_bound(L2, L2 + lis2, backwards[i]) - L2; 
            L2[pos2] = backwards[i];
            L[pos] = weights[i]; 
            if(pos+1 > lis){
                lis = pos+1; 
            }
            if(pos2 +1 > lis2){
                lis2 = pos2+1; 
            }
            if(pos + 1 + pos2 > max) max = pos + pos2 + 1; 
        }
        printf("%d\n", max);
    }
    return 0; 
}