/*
1612B
ac
*/

#include <cstdio>

int main(){
    int t; scanf("%d", &t);
    while(t--){
        int n, a, b; scanf("%d %d %d", &n, &a, &b);
        int arr[n], brr[n+1] = {}, r1 = n/2, r2 = n/2, mx = n;
        arr[0] = a; brr[a] = 1; r1--; 
        int ind = 1; 
        while(r1){
            if(mx == b){
                mx--; continue; 
            }
            if(brr[mx] == 0){
                arr[ind++] = mx; 
                brr[mx] = 1; 
                mx--;
                r1--;
            }
            else mx--;
        }
        if(mx < a){
            printf("-1\n"); continue; 
        }
        if(mx == a) mx--;
        if(mx > b){

            printf("-1\n"); 
            continue; 
        }
        else{
            arr[n-1] = b; 
            brr[b] = 1; 
            r2--;
            while(r2){
                if(brr[mx] == 0){
                    arr[ind++] = mx; 
                    brr[mx] = 1; 
                    mx--; 
                    r2--;
                }
                else mx--;
            }
        }
        for(int i = 0; i < n; i++){
            if(i) printf(" %d", arr[i]); 
            else printf("%d", arr[i]); 
        }
        printf("\n"); 
    }
    return 0;
}