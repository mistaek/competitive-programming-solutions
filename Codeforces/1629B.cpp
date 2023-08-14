/*
1629A
WIP
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int l, r, k; scanf("%d %d %d", &l, &r, &k);
        if(r - l == 0){
            if(r > 1) printf("YES\n"); 
            else printf("NO\n");
        }
        else{
            int o;
            if((r - l + 1) % 2 == 0){
                o = (r-l+1)/2; 
                
            }
            else{
                o = (r-l+1)/2; 
                if(l % 2) o++;
            }
            if(k >= o) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}