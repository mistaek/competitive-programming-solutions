/*
1591A
WIP
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        int td, last = 0;
        int ans = 1, d = 0;
        for(int i = 0; i < n; i++){
            int td; scanf("%d", &td); 
            if(td == 1){
                ans++;
                if(i && last) ans += 4;
            }
            else{
                if(i && last == 0) d = 1;
            }
            last = td; 
        }
        if(d) printf("-1\n"); 
        else printf("%d\n", ans);
    }
    return 0;
}