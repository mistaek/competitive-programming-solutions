/*
Vacation (DPC)
[NAME]
AC
*/

#include <cstdio>
#include <iostream>

using namespace std; 

#define max(a, b) ((a > b) ? a : b)
int choices[100005][3], memo[10005][3];

int days; 


// too slow
//iterative needed? 
int main(){
    scanf("%d", &days); 
    for(int i = 0; i < days; i++){
        scanf("%d %d %d", &choices[i][0], &choices[i][1], &choices[i][2]); 
    }
    for(int i = 0; i < 3; i++) memo[0][i] = choices[0][i];
    for(int i = 0; i <= days;i++){ //day 
        for(int j = 0; j < 3; j++){//task day 1
            for(int k = 0; k < 3; k++){//task on second day
                if(j != k){             //if they are different
                    memo[i+1][k] = max(memo[i+1][k], memo[i][j] + choices[i+1][k]); 
                }
            }
        }
    }
    int ans = 0; 
    /*for(int i = 0; i <= days; i++){
    	for(int j = 0; j < 3; j++){
    		printf("%d ", memo[i][j]);
    	}
    	printf("\n");
    }*/
    for(int i = 0; i < 3; i++){
        ans = max(ans, memo[days-1][i]);
    }
    printf("%d\n", ans);
    return 0; 
}