/*
UVa 147
[NAME]
AC
*/ 

#include <cstdio>
#include <cstring>

int vals[12] = {10000, 5000, 2000, 1000, 500, 200, 100, 50 , 20, 10, 5}; 

long long memo[15][30005]; 

long long permute(int type, int val){
    if(val == 0) return 1; 
    if(val < 0 || type == 11) return 0; 
    if(memo[type][val] != -1) return memo[type][val];

    return memo[type][val] = permute(type, val-vals[type]) + permute(type+1, val);
}

//cool output trick!
int main(){
	
    double in; 
    while(scanf("%lf", &in), in > 0){
    	memset(memo, -1, sizeof(memo));
        printf("%6.2lf%17lld\n", in, permute(0, (int)(in*100 +0.5)));
    }
    return 0; 
}