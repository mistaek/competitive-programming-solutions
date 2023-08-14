/*
UVa 10718 Bit Mask
[NAME]
AC
*/

#include <cstdio>

typedef long long ll; 

int main(){
    ll m, l, r;
    while(scanf("%lld %lld %lld", &m, &l, &r)!= EOF){

        ll best = 0; 
        for(int i = 32; i >= 0; i--){ // see if each bit should be added
			ll one = 1; 
			if(m &(one << i)){
				if((best | (one << i)) <= l) best|= (one << i); 
			}
			else{
				if((best | (one << i)) <= r) best |= (one << i); 
			}
			
        }
        printf("%lld\n", best);
    }
    return 0;
}