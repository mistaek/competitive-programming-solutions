/*
1573B
ac - you are too slow
*/

#include <cstdio>
#include <algorithm>

using namespace std; 


int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        int a[n], p[2*n + 1];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 0; i < n; i++){
            int in; scanf("%d", &in); 
            p[in-1] = i;
        }
        for(int i = 2*n-3; i >= 1; i--){
            p[i] = min(p[i], p[i+2]);
        }
        int ans = 1e9;
        for(int i = 0; i < n; i++){
            ans = min(ans, i + p[a[i]]);
        }
        printf("%d\n", ans);
    }
    return 0;
}