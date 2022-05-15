/*
ecoo2021p3
wip
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    pair<int, int> best[n+1] = {};
    for(int i = 0; i < k; i++){
        int a, b, c; scanf("%d %d %d", &a, &b, &c);
        if(c > best[b].first){
            best[b] = {c, a};
        }
    }
    for(int i = 1; i <= n; i++){
        if(i-1) printf(" ");
        if(best[i].second == 0) printf("-1"); 
        else printf("%d", best[i].second);
    }
    return 0;
}