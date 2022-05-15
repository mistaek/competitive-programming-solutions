/*
uva 668
ray
AC
*/

#include <cstdio>

int main(){
    int a; scanf("%d", &a);
    while(a--){
        int b;  
        scanf(" %d", &b);
        int arr[b] = {};
        int i, end; 
        for(i = 2; i <= b; i++){
            arr[i] = i; b-= i;
        }
        end = i;
        while(b){
        	if(i-1 == 1) i = end;
            arr[--i]++;
            b--;
        }
        i = 2; 
        while(arr[i]){
            if(i == 2) printf("%d", arr[i]); 
            else printf(" %d", arr[i]);
            i++;
        }
        printf("\n");

        if(a) printf("\n");
    }
    return 0;
}