/*
RB P2
ac
*/

#include <cstdio>

int main(){
    int TC; scanf("%d", &TC); 
    for(int tc = 1; tc <= TC; tc++){
        long long n; scanf("%lld", &n); 
        long long i = 1; long long ans = 0;  
       
        for(i; i * i <= n; i++){
            if(n % i) continue; 
            long long pow = 1, j = i; 
            while(j >= 10){
                pow *= 10;
                j/= 10;
            }
            j = i; 
            while(j > 0){
                if(pow == 0) break;
                long long fs, ls; 
                fs = j/pow; 
                ls = j % 10;
                if(fs != ls){j = -1; break;} 
                j %= pow;  j/= 10; 
                pow/= 100;
            }
            
            if(j != -1) ans++; 
            pow = 1; j = n/i;
            if(j == i) continue; 
             while(j >= 10){
                pow *= 10;
                j/= 10;
            }
            j = n/i; 
            while(j > 0){
                if(pow == 0) break;
                long long fs, ls; 
                fs = j/pow; 
                ls = j % 10;
                if(fs != ls){j = -1; break;} 
                j %= pow;  j/= 10; 
                pow/= 100;
            }

            if(j != -1) ans++; 
        }
        printf("Case #%d: %lld\n",tc,  ans);
    }
    return 0;
}