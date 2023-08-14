/*
Round B P3
ac
*/

#include <cstdio>
#include <algorithm>
#include <map>
using namespace std; 


map<pair<pair<long long, long long>, long long>, long long> memo;

long long n, d;  
long long a[400];
long long modd(long long a){
    long long ret = a% d; 
    if(ret < 0) ret += d;
    return ret; 
}

long long compute(long long l, long long r, long long f){

    if(memo.count({{l, r}, f})) return memo[{{l, r}, f}];
    if(l == r){
        long long temp = a[l];
        temp += f; 
        temp = modd(temp);
        return memo[{{l, r}, f}] = min(d - temp, temp);
    }
    if(l < r){
        long long temp1 = a[l], temp2 = a[r]; 
        temp1 += f; 
        temp2 += f; 
        temp1 = modd(temp1); temp2 = modd(temp2);
        long long ans1 = temp1 + compute(l+1, r, modd(f - temp1)), ans2 = d-temp1 + compute(l+1, r, modd(f + d - temp1));
        long long ans3 = temp2 + compute(l, r-1, modd(f - temp2)), ans4 = d-temp2 + compute(l, r-1, modd(f + d- temp2));
        return memo[{{l, r}, f}] = min(min(ans1, ans2), min(ans3, ans4));
    }
    
}
int main(){
    int TC; scanf("%d", &TC); 
    for(int tc= 1; tc <= TC; tc++){
        scanf("%lld %lld", &n, &d);
		for(int i = 0; i < n; i++) scanf("%lld", &a[i]);

        printf("Case #%d: %lld\n", tc, compute(0, n-1, 0));
        memo.clear(); 
        
    }
    return 0;
}