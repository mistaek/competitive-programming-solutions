/*
dpj
ray
AC
order of op strange
*/
#include <cstdio>
#include <cstring>

using namespace std; 

int n, c[4] = {}; 
double m[301][301][301] = {}; //sstate 


double btrk(int a, int b, int c){
    if(a +b +c == 0) return 0.0; // 0 remaining roll until done
    if(m[a][b][c] > -1.0) return m[a][b][c]; // remaining rolls already calculated
    double rs = (double)n/(a+b+c); //number of rolls before a sushi is eaten 
    double r = 0.0;
    if(a) r+= (double) (a*(btrk(a-1, b, c) + rs)/(a+b+c));
    if(b) r+= (double) (b * (btrk(a+1, b-1, c) + rs)/(a+b+c));
    if(c) r+= (double) (c* (btrk(a, b+1, c-1) + rs)/(a+b+c));
    
    return m[a][b][c] = r;

}

int main(){
    scanf("%d", &n);
    //printf("%d\n", n);
    for(int i = 0; i < n; i++){
        int a; scanf("%d", &a);
        //printf("%d ", a);
        c[a]++;
    }
    printf("\n");

    //apparently memset doesn't work :/ memset(m, -1.0, sizeof(m));

    for(int i = 0; i < 301; i++){
        for(int j = 0; j < 301; j++){
            for(int k = 0; k < 301; k++){
                m[i][j][k] = -1.0;
            }
        }
    }
    double out = btrk(c[1], c[2], c[3]);
    
    printf("%.9lf", out);
    //bottom up looks harder / impossible :(
    return 0;
}