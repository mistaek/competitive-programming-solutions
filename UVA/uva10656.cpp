/*
UVa 10656 Maximum Sum (II)
[NAME]
AC
*/

#include <cstdio>
int main(){
    int l; 
    while(scanf("%d", &l), l != 0){
        int nums[l] = {}, max = 0;  
        for(int i = 0; i < l; i++ ) {scanf("%d", &nums[i]); max += nums[i];}
        int sum = 0, idx = 0;  
        if(max == 0) printf("0\n");
        while(sum < max){
            if(nums[idx] != 0){ 
                sum+= nums[idx]; 
            	if(sum == max) printf("%d\n", nums[idx]);
            	else printf("%d ", nums[idx]); 
            }
            idx++;
        }
    }
    return 0; 
}