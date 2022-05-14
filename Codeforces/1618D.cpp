/*
1618D
u are dumb lol
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n, k; scanf("%d %d", &n, &k);
        int a[n], f[n-1], psa[n]; 
        for(int i = 0; i < n; i++){ 
            scanf("%d", &a[i]);  
        }
        sort(a, a+n); 
        for(int i = 0; i < n; i++){ 
            psa[i] = a[i]; 
            if(i){
                psa[i] += psa[i-1];
                f[i-1] = a[i-1]/a[i];
            }
        }
        int ind = n-2, ans = 0;  
        while(k){
            ans += f[ind];
            ind -=2; 
            k--;
        }
        //printf("%d %d\n", ans, ind);
        if(ind+1 >= 0) {ans += psa[ind+1];}
        printf("%d\n", ans);
    }
    return 0;
}