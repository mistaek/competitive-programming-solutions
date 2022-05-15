#include <cstdio>
//O(n^2) should work, very low input size! 

int main(){
    int TC; scanf("%d", &TC); 
    while(TC--){
        int n; scanf("%d", &n); 
        int prefx[5001] = {}, sum = 0; 
        for(int i = 0; i < n; i++){
            int num; scanf("%d", &num); 
            for(int j = 1; j <= num; j++) prefx[j]++; // O(n^2)
            sum += prefx[num];
        }
        printf("%d\n", sum); 

    }
    return 0; 
}