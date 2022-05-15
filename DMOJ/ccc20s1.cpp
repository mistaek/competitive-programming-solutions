/*
ccc20s1
ac
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int n; scanf("%d", &n);
    pair<long long, long long> p[100001];
    for(int i = 0; i < n; i++){
        scanf("%lld %lld", &p[i].first, &p[i].second); 
      
    }
    sort(p, p+n);
    double ans = 0; 
    for(int i = 1; i < n; i++){
        double s = (double)(p[i].second - p[i-1].second)/(p[i].first - p[i-1].first);
        if(s < 0) s*=-1.0;
        ans = max(ans, s);
       
    }
    printf("%.6lf\n", ans);
    return 0;
}