/*
Round B P1
ac
*/

#include <cstdio>
#include <math.h>

using namespace std; 
int main(){
    int tc; scanf("%d", &tc); 
    for(int TC = 1; TC <= tc; TC++){
        long long r, a, b; scanf("%lld %lld %lld", &r, &a, &b);
        long long sum = 0; int swi = 0;
        while(r > 0){
            sum += r * r; 
            if(swi) r /= b; 
            else r *= a;
            swi = 1- swi;
        }

        printf("Case %d: %.6lf\n", TC, sum * M_PI); 
    }
    return 0;
}   