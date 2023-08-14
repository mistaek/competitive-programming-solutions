/*
dpi
ray
AC
*/

#include <cstdio>

double chances[3000][3000] = {};
double chance[3000] = {};
int n;

int main(){
    scanf("%d", &n); 
    for(int i = 0; i < n; i++){
        scanf(" %lf", &chance[i]);
    }

    chances[0][0] = 1.0 - chance[0];
    chances[0][1] = chance[0];
    //printf("%d: %lf %lf %lf\n",0, chances[0][0], chances[0][1], chances[0][2]);
    for(int i = 1; i < n; i++){
        //printf("%d: ", i);
        
        for(int j = 0; j <= n; j++){
            chances[i][j] += ((1.0-chance[i]) * chances[i-1][j]) + ((chance[i]) * chances[i-1][j-1]);
            //printf("%lf ", chances[i][j]);
        }
        //printf("\n");
    }
    double out = 0;
    for(int j = n/2 + 1; j <= n; j++){
        out+= chances[n-1][j];
    }
    printf("%.9lf", out);
    return 0;
}