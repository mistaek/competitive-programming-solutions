/*
1822G2
tle MADGE
*/

#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <vector>
#include <set>
using namespace std; 

int pn; 
vector<int> primes; 
vector<int> a(200000); 

map<int, int> cnt; 
long long ans = 0;
int checkcnt = 0;
vector<pair<int, int>> posval; 
vector<int> divisors; 

void check(int curval, int i){
    if(i >= posval.size()){
        divisors.push_back(curval);
        return; 
    }
    checkcnt += posval[i].second;
    int cur = 1; 
    for(int j = 0; j <= posval[i].second; ++j){
        check(curval * cur, i+1);
        cur *= posval[i].first; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    bool marked[32000] = {true, true};
    for(int i = 2; i < 32000; ++i){
        if(!marked[i]){
            for(int j = i * i; j < 32000; j += i) marked[j] = true; 
            primes.push_back(i);
        }
    }
    pn = primes.size();

    int t; cin >> t; 
    while(t--){
        ans = 0;
        cnt.clear();
        int n; cin >> n;

        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
            ++cnt[a[i]];
        }

        for(auto [k, ct] : cnt){
            if(ct >= 3){
                ans += (long long) ct * (ct-1) * (ct-2);
            }
            posval.clear(); 
            checkcnt = 0;
            auto num = k; 
            for(int i = 0; i < primes.size() && primes[i] * primes[i] <= num; ++i){
                if(num % (primes[i] * primes[i]) == 0){
                    posval.push_back({primes[i], 0});   
                }
                while(num % (primes[i] * primes[i]) == 0){
                    num /= (primes[i] * primes[i]);
                    posval.back().second++;
                }
            }
            divisors.clear();
            check( 1, 0);
            //cout << k << "\n"; 
            for(auto u : divisors){
                //cout << u << " "; 
                if(u == 1) continue; 
                if(k % (u * u)) continue; 
                auto it1 = cnt.find(k/u), it2 = cnt.find(k/(u*u)); 
                if(it1 == cnt.end() || it2 == cnt.end()) continue; 
                ans += (long long) ct * it1->second * it2->second;
            }
            //cout << "\n";
            //cout << k << " " << checkcnt << "\n";
        }
        cout << ans << "\n";      
    }
    return 0;
}