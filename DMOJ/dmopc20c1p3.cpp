/*
dmopc20c1 p3
wip
*/

#include <cstdio>


int main(){
    long long n; scanf("%lld", &n);
    long long a[n], maximum = -1000000001, maxi = -1; 
    for(long long i = 0; i < n; i++){
        scanf("%lld", &a[i]); 
        if(a[i] > maximum){
            maxi = i; maximum = a[i];
        }
    }
    long long ans = 0;
    for(long long i = 0; i < maxi; i++){
        if(i){
        	
            if(a[i] <a[i-1]){ ans+= a[i-1]-a[i]; a[i] = a[i-1];}
            
        }
    }
    for(long long i = n-1; i > maxi; i--){
        if(i+1 < n){
            if(a[i] < a[i+1]){ ans+= a[i+1]-a[i]; a[i] = a[i+1];}
        }
    }
    printf("%lld\n", ans);
    return 0;
}