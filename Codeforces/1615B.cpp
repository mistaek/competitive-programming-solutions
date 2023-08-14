/*
1615B
ac
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int a[200001][32] = {};

int main(){
    for(int i = 1; i <= 200000; i++){
        for(int j = 0; j < 30; j++){
            if(i & (1 << j)) a[i][j]++;
            a[i][j] += a[i-1][j];
        }
    }    
    int t; scanf("%d", &t); 
    while(t--){
        int l, r; scanf("%d %d", &l, &r); 
        int ans = 0; 
        for(int i = 0; i < 30; i++){
            ans = max(a[r][i] - a[l-1][i], ans);
        }
        ans = r - l + 1 - ans;
        printf("%d\n", ans);
    }
    return 0;
}