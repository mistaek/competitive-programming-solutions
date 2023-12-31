/*
1905D
AC
*/

#include <iostream>
#include <deque>

using namespace std; 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        long long p[n];
        deque<pair<long long, long long>> pmex; 
        for(int i = 0; i < n; i++) cin >> p[i];
        int c[n+1] = {}, mex = 0, cnt = 0;
        long long sum = 0, ans = 0; 
        for(int i = 0; i < n; i++){
            c[p[i]] = 1; 
            if(p[i] == mex){
                if(cnt) pmex.push_back({mex, cnt});
                while(c[mex]) mex++;
                cnt = 1;
            }
            else{
                cnt++; 
            }

            sum += mex; 
        }
        
        ans = sum;
        pmex.push_back({n, 1});
        for(int i = 0; i < n-1; i++){
            pair<long long, long long> front = pmex.front(); //should always exist
            pmex.pop_front();
            sum -=front.first; 
            if(front.second> 1) pmex.push_front({front.first, front.second -1});

            pair<long long, long long> back = pmex.back(); 
            int tot = 0; 
            while( back.first > p[i]){
                pmex.pop_back();
                
                sum -= back.first * back.second;
                tot += back.second; 
                if(!pmex.empty()) back = pmex.back();
                else break; 
            }
            
            if(tot) pmex.push_back({p[i], tot});
            
            sum += p[i] * tot + n; 
            ans = max(ans, sum);
            pmex.push_back({n, 1});

        }
        cout << ans << "\n";
    }
    return 0;
}