/*
QR2022 
ac
*/

#include <cstdio>
#include <algorithm>

using namespace std; 


int main(){
    int t; scanf("%d", &t); 
    for(int tc = 1; tc<= t; tc++){
        printf("Case #%d: ", tc);
        int n; scanf("%d", &n); 
        int d[n]; for(int i = 0; i < n; i++) scanf("%d", &d[i]);

        sort(d, d+n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(d[i] > ans) ans++;
        }
        printf("%d\n", ans);
        
    }
    return 0;
}