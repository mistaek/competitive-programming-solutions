/*
tle - solution correct but too many states calculated (only 2 per n necessary)
*/

#include <cstdio>
#include <map>
#include <algorithm>

using namespace std; 

map<pair<int, int>, long long>  memo;
int a[1000][100]; 
int m[1000][2] = {};
int n, p; 
long long compute(int curn, int curp){
    if(memo.count({curn, curp})) return memo[{curn, curp}];
    if(curn == n) return 0;
    

    long long hi = m[curn][1] - m[curn][0] + abs(m[curn][0] - curp);
    long long lo = m[curn][1] - m[curn][0] + abs(m[curn][1] - curp);
	//printf("%lld %lld %lld %lld\n", curn, curp, hi, lo); 
    memo[{curn, curp}] = min(hi + abs(m[curn][1] - a[curn][0]), lo + abs(m[curn][0] - a[curn][0])) + compute(curn+1, a[curn][0]);
    for(int i = 1; i < p; i++){
        memo[{curn, curp}] = min(memo[{curn, curp}], min(hi + abs(m[curn][1] - a[curn][i]), lo + abs(m[curn][0] - a[curn][i])) + compute(curn + 1, a[curn][i])); 
    }
    return memo[{curn, curp}];
}
int main(){
    int TC; scanf("%d", &TC); 
    for(int tc = 1; tc <= TC; tc++){
        memo.clear();
        scanf("%d %d", &n, &p);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < p; j++){
                scanf("%d", &a[i][j]); 
                if(j ==0){
                    m[i][0] = a[i][j]; 
                    m[i][1] = a[i][j]; 
                }
                m[i][0] = min(m[i][0], a[i][j]); 
                m[i][1] = max(a[i][j], m[i][1]); 
            }
            //printf("%d %d\n", m[i][0], m[i][1]);
        }

        printf("Case #%d: %lld\n", tc, compute(0, 0)); 

    }
    return 0;
}