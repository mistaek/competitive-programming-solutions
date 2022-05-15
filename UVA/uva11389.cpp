/*
UVa 11389 - The Bus Driver Problem
[NAME]
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
//load balancing -- greedy


bool greater(int a, int b){
    return a > b; 
}
int main(){
    int n, d, r; 
    while(scanf("%d %d %d", &n, &d, &r), n) {
        int morn[n], eve[n]; 
        for(int i = 0; i < n; i++){
            scanf("%d", &morn[i]); 
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &eve[i]); 
        }

        sort(morn, morn+n, greater); 
        sort(eve, eve+n); 
        int ans = 0; 
        for(int i = 0; i < n; i++){
            int sum = morn[i] + eve[i]; 
            if(sum > d) ans+= (sum-d) *r; 
        }
        printf("%d\n", ans);
    }
    

    return 0; 
}