/*
uva 11369
ray
AC
*/

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std; 
int main(){
    int tc; scanf("%d", &tc);
    while(tc--){
        int n; scanf("%d", &n);
        int ans = 0, arr[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }

        sort(arr, arr+n, greater<int>());

        for(int i = 0; i < n; i++){
            if( (i+1) % 3 == 0) ans+= arr[i];
        }

        printf("%d\n", ans); 

    }
    return 0;
}