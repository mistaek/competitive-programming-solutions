/*
dpk
ray
AC
*/

#include <cstdio>

#define min(a, b) ((a < b) ? a : b)
#define max(a, b) ((a > b) ? a : b)
int main(){
    int n, r; scanf("%d %d", &n, &r);
    int arr[n];
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]); 

    int m[100005] = {};
    for(int i = 0; i <= r; i++){
        for(int j : arr){
            if(i - j >= 0){
                m[i] = max(m[i], 1- m[i -j]);
            }
        }
    }
    if(m[r]) printf("First");
    else printf("Second");
    return 0;
}