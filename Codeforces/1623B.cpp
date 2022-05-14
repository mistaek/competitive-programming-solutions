/*
1623A
WIP
*/

#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        pair<int, pair<int, int>> ranges[n]; 
        for(int i = 0; i < n; i++){
            int l, r; scanf("%d %d", &l, &r); 
            ranges[i] = {r-l, {l, r}};
        }
        sort(ranges, ranges+n, greater<pair<int, pair<int, int>>>());
        int kicked[n+1] = {};
        for(int i = 0; i < n; i++){
            int l = ranges[i].second.first, r = ranges[i].second.second; 
            if(l == r) printf("%d %d %d\n", l, l, l); 
            else{
                for(int j = i +1; j < n; j++){
                    if(ranges[j].second.first == l){
                        printf("%d %d %d\n", l, r, ranges[j].second.second + 1); 
                        break;
                    }
                    else if(ranges[j].second.second == r){
                        printf("%d %d %d\n", l, r, ranges[j].second.first-1);
                        break;
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}