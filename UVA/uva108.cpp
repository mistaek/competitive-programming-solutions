/*
UVa 108 Maximum Sum
[NAME]
WIP
*/

//DP + greedy

#include <cstdio>

#define max(a, b) ((a < b) ? b : a)

int main(){
    int n; scanf("%d", &n); 
    int square[n][n]; 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &square[i][j]);
            if(i > 0) square[i][j] += square[i-1][j]; 
            if(j > 0) square[i][j] += square[i][j-1];
            if(i > 0 && j > 0) square[i][j] -= square[i-1][j-1];
        }
    }

    int max = -127*100*100, sum = 0;  
    //calculate squares from i, j to x, y
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int x = i; x < n; x++){
                for(int y = j; y < n; y++){
                    sum = square[x][y]; 
                    if(i > 0) sum -= square[i-1][y]; 
                    if(j > 0) sum -= square[x][j-1]; 
                    if(j > 0 && i > 0) sum += square[i-1][j-1]; 
                    max = max(max, sum); 
                }
            }

        }
    }
    printf("%d\n", max); 
    return 0; 
}