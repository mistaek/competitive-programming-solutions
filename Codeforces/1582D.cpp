/*
1582D
ac
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int gcd(int a, int b){
    return (b == 0)? a : gcd(b, a % b);
}
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n);
        int a[n], b[n] = {}; 
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        
        for(int i = 1; i < n; i+=2){
            int temp = b[i-1] - a[i];
            if(temp){
                b[i-1] -= a[i]; 
                b[i] += a[i-1];
            }
            else{
                b[i-1] += a[i];
                b[i] -= a[i-1];
            }
        }
        if(n % 2){
            int temp = b[n-2] - a[n-1];
            if(temp){
                b[n-2] -= a[n-1]; 
                b[n-1] += a[n-2];
            }
            else{
                b[n-2] += a[n-1]; 
                b[n-1] -= a[n-2];
            }
            
        }
        int g = abs(b[0]);
        for(int i = 1; i < n; i++){
            g = gcd(g, abs(b[i]));
        }
        for(int i = 0; i < n; i++){
            if(i) printf(" %d", b[i]/g); 
            else printf("%d", b[i]/g);
        }
        printf("\n");

    }
    return 0;
}