/*
1591B
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        int a[n], mx = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]); 
            mx = max(a[i], mx);
        
        }
        int c = a[n-1], ans = 0; 
        for(int i = n-1; i>= 0; i--){
            if(c == mx) break; 
            if(a[i] > c) ans++;
            c = max(a[i], c); 
        }
        printf("%d\n", ans);
    }
    return 0;   
}