/*
dmopc 2019 7 p0
ray
wip
*/
#include <cstdio>

//how are we still in 2019 :(

int main(){
    int _a, _b, _c, _d; scanf("%d %d %d %d", &_a, &_b, &_c, &_d);
    double a = (double) _a, b = (double)_b, c = (double) _c, d = (double) _d; 
    printf("%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n", (a+b)/2, (a+c)/2, (a+d)/2, (b+c)/2, (b+d)/2, (c+d)/2, (a+b+c)/3, (a+b+d)/3, (a + c + d)/3, (b+c+d)/3, (a+b+c+d)/4 );
    return 0;
}