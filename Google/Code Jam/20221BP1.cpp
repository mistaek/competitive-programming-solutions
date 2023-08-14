/*
ac
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int TC; scanf("%d", &TC); 
    for(int tc = 1; tc <= TC; tc++){
        int n; scanf("%d", &n); int l = 0, r = n-1, cur = 0, a[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]); 
        }
        int ans = 0;
        while(l <= r){
            if(a[l] <= a[r]){
                if(a[l] >= cur) ans++; 
                cur = max(a[l], cur); 
                l++;
            }
            else{
                if(a[r] >= cur) ans++; 
                cur = max(a[r], cur); 
                r--;
            }
        }
        printf("Case #%d: %d\n",tc, ans);
    }
    return 0;
}