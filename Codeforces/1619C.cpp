/*
1619C
ac
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long a1, s1; scanf("%lld %lld", &a1, &s1);
        long long a[25] = {}, s[25] = {}; 
        int ind = 0;
        int l1, l2; 
        while(a1 > 0){
            a[ind] = a1 % 10; 
            a1 /= 10; 
            ind++;
        }
        l1 = ind; 
        ind = 0; 
        while(s1 > 0){
            s[ind] = s1 % 10; 
            s1/= 10; 
            ind++;
        }
        l2 = ind;

        bool t =true;
        long long b[20] = {};
        ind = 0; 
        int i1 = 0, i2 = 0;
        //printf("%d %d\n", l1, l2);
        while(i1 < l1 || i2 < l2){
            if(a[i1] <= s[i2]){
                b[ind] = s[i2] - a[i1];
                ind++; i1++; i2++; 
            }
            else{
                if(s[i2+1] == 1){
                    b[ind] = 10 + s[i2] - a[i1];
                    ind++; i1++; i2 += 2; 
                }
                else{
                    t = false; 
                    break; 
                }
            }
        }
        if(t){
            for(int i = ind-1 ; i >= 0; i--) {
                if(t && b[i] == 0) continue; 
                if(b[i]) t= false;
                printf("%lld", b[i]); 
            }
            printf("\n");
        }
        else printf("-1\n"); 

    }
    return 0;
}