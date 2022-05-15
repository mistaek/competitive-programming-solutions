/*
UVa 10827 Maximum sum on a torus
[NAME] 
AC
*/

#include <cstdio>

#define max(a, b) ((a < b) ? b : a)
int main(){
    int TC; scanf("%d", &TC); 
    while(TC--){
        int n; scanf("%d", &n); 
        int torus[n][n]; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &torus[i][j]); 
            }
        }

        //compute
        int ansgrid[2*n][2*n]; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ansgrid[i][j] = torus[i][j]; 
                if(i > 0) ansgrid[i][j] += ansgrid[i-1][j];
                if(j > 0) ansgrid[i][j] += ansgrid[i][j-1]; 
                if(i > 0 && j > 0) ansgrid[i][j] -= ansgrid[i-1][j-1];
            }
            for(int j = n; j < 2*n; j++){
                ansgrid[i][j] = torus[i][j-n]; 
                if(i > 0) ansgrid[i][j] += ansgrid[i-1][j];
                if(j > 0) ansgrid[i][j] += ansgrid[i][j-1]; 
                if(i > 0 && j > 0) ansgrid[i][j] -= ansgrid[i-1][j-1]; 
            }
        }
        for(int i = n; i <  2* n; i++){
            for(int j = 0; j < n; j++){
                ansgrid[i][j] = torus[i-n][j]; 
                if(i > 0) ansgrid[i][j] += ansgrid[i-1][j];
                if(j > 0) ansgrid[i][j] += ansgrid[i][j-1]; 
                if(i > 0 && j > 0) ansgrid[i][j] -= ansgrid[i-1][j-1];
            }
            for(int j = n; j < 2*n; j++){
                ansgrid[i][j] = torus[i-n][j-n]; 
                if(i > 0) ansgrid[i][j] += ansgrid[i-1][j];
                if(j > 0) ansgrid[i][j] += ansgrid[i][j-1]; 
                if(i > 0 && j > 0) ansgrid[i][j] -= ansgrid[i-1][j-1]; 
            }
        }

        //get the answer
        
        int best = -999999999, sum = 0; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int x = i; x < i+ n; x++){
                    for(int y = j; y < j+ n; y++){
                        int sum = ansgrid[x][y]; 
                        if(i > 0) sum -= ansgrid[i-1][y]; 
                        if(j > 0) sum -= ansgrid[x][j-1]; 
                        if(i > 0 && j > 0) sum+= ansgrid[i-1][j-1]; 
                        best = max(best, sum);  
                    }
                }
            }
        }
        printf("%d\n", best); 
       
    }
    return 0; 
}
