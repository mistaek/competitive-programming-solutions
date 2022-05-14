/*
1608B
ac - weird problem tbh
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n, a, b; scanf("%d %d %d", &n, &a, &b); 
        if(a + b > n-2 || abs(b - a) > 1){
            printf("-1\n"); 
            continue; 
        }
        int arr[n]; 
        if(a >= b) for(int i = 0; i < n; i++) arr[i] = i+1; 
        else{
            for(int i = 0; i < n; i++){
                arr[i] = n - i;
            }
        }
        int ind = 1; 
        while(a && b && ind < n-2){
            swap(arr[ind], arr[ind+1]); 
            a--; 
            b--;
            ind += 2;
        }
        if(a || b) swap(arr[n-1], arr[n-2]); 
        
            for(int i = 0; i < n; i++){
                if(i) printf(" %d", arr[i]); 
                else printf("%d", arr[i]); 
            }
        
            printf("\n");
            }
    return 0;
}