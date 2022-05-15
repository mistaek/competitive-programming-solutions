/*
GlobeX 19 S2
ray
wip
*/

#include <cstdio>
#include <cmath>
typedef long long ll; 

int coef[2][6] = {};

double calc(int f, double x){
    double ret = 0; 
    for(int i = 5; i >= 0; i--){
        ret += coef[f][i]*pow(x, i);   
    }
    return ret; 
}
int main(){
    int n; scanf("%d", &n);
    
    for(int i = n; i >= 0; i--){
        scanf("%d", &coef[0][i]);  
    }
    scanf("%d", &n);
    for(int i = n; i >= 0; i--){
        scanf("%d", &coef[1][i]);
    }

    int _a, _b; scanf("%d %d", &_a, &_b); 
    double a = (double) _a, b = (double) _b; 
    
    //binary search 
    

    double lo = a, hi = b; 

    while(1){
        fabs(calc(1, lo) - calc(0, lo));
        if(fabs(calc(1, lo) - calc(0, lo)) < __DBL_EPSILON__) break;
        double mid = (lo+hi)/2.0; 
        if(calc(0, mid) == calc(1, mid)){
            lo = mid; break; 
        }
        else if((calc(0, mid) > calc(1, mid) && calc(0, hi) < calc(1, hi)) || (calc(0, mid) < calc(1, mid) && calc(0, hi) > calc(1, hi))){
            lo = mid; 
        }
        else if( (calc(0, lo) > calc(1, lo) && calc(0, mid) < calc(1, mid)) ||(calc(0, lo) < calc(1, lo) && calc(0, mid) > calc(1, mid))){
            hi = mid; 
        }
    }

    printf("%.8lf", lo);
    //printf("\n%lf %lf\n", calc(0, lo), calc(1, lo)); 
    
    return 0;
}