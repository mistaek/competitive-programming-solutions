/*
CCC 17 S3
ray
wip
*/

#include <cstdio>

#define max(a, b) ((a > b) ? a : b)
#define min(a , b) ((a < b) ? a : b)
 
int nums[4001] = {}; 

int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int in; scanf("%d", &in); 
        nums[in]++; 
    }
    int maxl = 0, diff = 1;
    for(int i = 2; i <= 4000; i++){
        int lmaxl = 0; 
        for(int j = 1; j <= 2000; j++){
            if(j > i) break; 
            lmaxl+= min(nums[i-j], nums[j]); 
        }
        if(lmaxl > maxl){
            maxl = lmaxl; 
            diff = 1; 
        }
        else if(lmaxl == maxl){
            diff++;
        }
    }
    printf("%d %d", maxl/2, diff);
    return 0;
}