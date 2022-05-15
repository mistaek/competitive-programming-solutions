/*
An Easy Problem by bruce
Ray
WIP
*/

// this is lis with extra steps 
// narrator: it wasn't
#include <cstdio>

#define max(a, b) ((a > b) ? a : b)
#define min(a, b) ((a < b) ? a : b)
int main(){
    int easy = 0, e = 1;
    int n; scanf("%d", &n);
    int arr[n], bits[n] = {}; 
    for(int i = 0; i < n; i++){
        e = 1; 
        scanf("%d", &arr[i]);
        for(int j = 0; j < 30; j++) if(arr[i] & (1 << j)) e = max(e, bits[j] +1);
        for(int j = 0; j < 30; j++) if(arr[i] & (1 << j)) bits[j] = max(e, bits[j]);
        easy = max(easy, e);
    }
    printf("%d", easy);
    
    return 0;
}