/*
1629A
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n, k; scanf("%d %d", &n, &k);
        pair<int, int> a[n];
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i].first);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i].second);
        }
        sort(a, a+n);
        for(int i = 0; i < n; i++){
            if(k >= a[i].first){
                k+= a[i].second;
            }
            else break;
        }
        printf("%d\n", k);
        
    }
    return 0;
}