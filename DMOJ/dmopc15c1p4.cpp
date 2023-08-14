/*
dmopc15c1p4
by ray 
for eric 
AC
*/

#include <cstdio>
#include <cstring>
bool sieve[148735] = {};

int main(){
    int n, x; scanf("%d %d", &n, &x); 

    //sieve
    memset(sieve, true, sizeof(sieve)); 
    sieve[0] = false; 
    sieve[1] = false; 
    for(int i = 4; i < 148735; i+= 2) sieve[i] = false; 
    for(int i = 3; i < 148735; i+=2){
        if(sieve[i]){
            for(int j = i+i; j < 148735; j+= i) sieve[j] = false;  
        }
    }
    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(sieve[i]){
            for(int j = 0; j <= n - i; j += x ){
                //printf("Arrangement : %d %d %d\n", i, j, n-j-i);
                ans++; 
                if(n-i-j) ans++; 
            }
        }

    }
    printf("%d", ans);
    return 0;
}