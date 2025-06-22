/*
s25e
*/

#include <iostream>
#include <numeric>
#include <limits>
#include <vector>
using namespace std; 

int main(){
    int t; cin >> t; 
    //sieve
    // 1e6 lg 1e6 
    vector<bool> isPrime(1e6 + 2, true); 
    vector<long long> primes; 
    for(long long i = 2; i <= 1e6; ++i){
        if(isPrime[i]){
            for(long long j = i*i; j <= 1e6; j+=i){
                isPrime[j] = false; 
            }
            primes.push_back(i); 
        }
    }

    while(t--){
        long long n, k; cin >> n >> k; 
        vector<pair<long long, long long>> factors;
        long long ans = 1e18;
        // 1e5 ops
        for(auto i : primes){
            if(i > k) break; 
            if(k % i == 0){
                int cnt = 0; 
                while(k % i == 0){
                    k /= i; ++cnt; 
                }
                factors.push_back({i, cnt});
            }
        }
        if(k > 1){
            factors.push_back({k, 1});
        }
        for(auto [i, c] : factors){
            long long cnt = 0; long long it = i;
            while(n/it){
                cnt += n/it; 
                if(numeric_limits<long long>::max()/it > i) it = i * it; 
                else break; 
            }
            /*cout << i << " " << c << "\n";
            cout << cnt << "\n"; */
            ans = min(ans, cnt/c);
        }
        cout << ans << "\n";
    }
    return 0;
}