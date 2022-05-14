/*
1579D
ac
*/

#include <cstdio>
#include <queue>


using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        long long n; scanf("%lld", &n);
        priority_queue<pair<long long, long long>> pq;
        queue<pair<long long, long long>> q; 
        for(long long i = 1; i <= n; i++){
            long long in; scanf("%lld", &in);
            if(in) pq.push(make_pair(in, i));
        }
        pair<long long,long long> f, s;
        long long ans = 0;
        while(!pq.empty()){
            f = pq.top(); pq.pop(); 
            if(pq.empty()) break; 
            s = pq.top(); pq.pop();
            if(f.first -1) pq.push({f.first-1, f.second});
            if(s.first - 1) pq.push({s.first-1, s.second});
            q.push({f.second, s.second});
            ans++; 
        }
        printf("%lld\n", ans); 
        while(!q.empty()){
            printf("%lld %lld\n", q.front().first, q.front().second); 
            q.pop();
        }
    }
    return 0;
}