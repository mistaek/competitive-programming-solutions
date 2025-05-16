/*
1621B
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n);
        long long ml, mr, mc; scanf("%lld %lld %lld", &ml, &mr, &mc); 
        long long lc = mc, rc = mc;
        printf("%lld\n", mc);
        for(int i = 1; i < n; i++){
            long long l, r, c; scanf("%lld %lld %lld", &l, &r, &c);
            if(l < ml && r > mr){
                lc = c; rc = c; mc = c; 
                ml = l; mr = r;
            }
            else if(l < ml && r == mr){
                lc = c; rc = min(rc, c); mc = c; ml = l; 
            }
            else if(l < ml){
                lc = c; mc = lc + rc; 
                ml = l; 
            }
            else if(r > mr && l == ml){
                rc = c; lc = min(lc, c); mc = c; 
                mr = r; 
            }   
            else if(l == ml && r == mr && c < mc){
                lc = min(lc, c); rc = min(rc, c); mc = c; 
            }
            else if(r > mr){
                rc = c; mc = lc + rc; 
                mr = r; 
            }
            else if(l == ml){
                lc = min(lc, c); mc = min(mc, lc + rc); 
            }
            else if(r == mr){
                rc = min(rc, c); mc = min(mc, lc + rc); 
            }
            printf("%lld\n", mc);
        }

    }
    return 0;
}