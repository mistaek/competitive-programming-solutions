/*
CCC '97 S2
[NAME]
AC
*/ 
#include <cstdio>
#include <cmath>

//almost, will finish later. 
int main(){
    int num;
    scanf("%d", &num); 
    while(num--){
        int sum[32005] = {}, dif[32005] = {};  

        int in; scanf("%d", &in);
        bool nast = false; 
        for(int i = 1; i <= sqrt(in) +0.5; i++){
            int d = in/i; 
            if( i * d == in){
                sum[i+ d]++;
                dif[abs(i -d)]++; 
                if((sum[i+d] && dif[i+d]) || (sum[abs(i-d)] && dif[abs(i-d)])){
                    printf("%d is nasty\n", in);
                    nast = true; 
                    break; 
                } 
            }
        }
        if(!nast) printf("%d is not nasty\n", in);

    }
    return 0; 
}