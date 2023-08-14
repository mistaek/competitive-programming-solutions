/*
1607C
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        long long a[n], psa[n] = {};
        for(int i = 0; i < n; i++){
            scanf("%lld", &a[i]);
            
        }
        sort(a, a+n); 

        //for(int i = 0; i < n; i++){printf("%lld ", a[i]);}
        //printf("\n");

        for(int i = 0 ; i < n; i++){
            psa[i] = a[i]; 
            if(i){
                a[i] -= psa[i-1];
            }
        }


        sort(a, a+n); 



        printf("%lld\n", a[n-1]);
    }
    return 0;
}