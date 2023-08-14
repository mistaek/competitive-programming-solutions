/*
DMOJ DPD
[NAME]
ac
*/

#include <cstdio>
#include <cstring>
#define max(a, b) ((a > b) ? a : b)
//rats long long is needed
typedef long long ll; 
ll w[105], v[105], memo[100005] = {}; // memo needed? 
ll n, cap;  

ll pick(){
	ll ans = 0; 
	for(int i = 0; i < n; i++){
		for(int j = cap; j >= 0; j--){
			if(j - w[i] >= 0){
			memo[j] = max(memo[j], memo[j-w[i]] + v[i]);
			ans = max(ans, memo[j]);
			}
		}
	}
	return ans;
}
int main(){
    scanf("%lld %lld", &n, &cap);
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &w[i], &v[i]);
    }
    printf("%lld", pick());
    return 0; 
}
