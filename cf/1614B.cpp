/*
1614B
ac
*/

#include <cstdio>
#include <functional>
#include <algorithm>
#include <cmath>
using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long n; scanf("%lld", &n);
        pair<long long, long long> v[n]; 
        for(long long i =0; i < n; i++){
            scanf("%lld", &v[i].first); 
            v[i].second = i + 1;
        }
        sort(v, v + n, greater<pair<long long, long long>>());
        long long seq[n+1] = {};
        long long ind = 1, neg = 0;  
        long long ans = 0; 
        for(int i = 0; i < n; i++){
            ans += abs(ind) * v[i].first;  
            seq[v[i].second] = ind; 
            if(neg == 0){
                ind = -ind; 
                neg = 1; 
            }
            else{
                neg = 0;
                ind = (-ind) + 1; 
            }
        }
        printf("%lld\n", 2 * ans); 
        for(int i = 0; i <= n; i++){
            if(i) printf(" %d", seq[i]); 
            else printf("%d", seq[i]); 
        }
        printf("\n");
    }
    return 0;
}