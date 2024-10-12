/*
752D
AC with editorial (missed one case)
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std; 
using hashpairs = pair<pair<long long, long long>, pair<long long, long long>>; 
long long MOD = 1e9+7;
int k ,n; 
hashpairs hashfn(const string& str){
    long long cur = 1, cur2 = 1;
    long long exp = 31, exp2 = 53;
    long long ans = 0, rev = 0;
    long long ans2 = 0, rev2 = 0;
    for(int i = 0; i < n; ++i){
        ans += cur * (str[i] - 'a' + 1);
        rev += cur * (str[n-1-i] - 'a' + 1);
        cur *= exp;
        cur %= MOD; 
        ans %= MOD; 
        rev %= MOD; 

        ans2 += cur2 * (str[i] - 'a' + 1); 
        rev2 += cur2*(str[n-1-i] - 'a' +1); 
        cur2 *= exp2; 
        cur2 %= MOD; 
        ans2 %= MOD; 
        rev2 %= MOD;

    }
    return {{ans, rev}, {ans2, rev2}};
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    cin >> k >> n; 
    multiset<pair<hashpairs, long long>> dict;

    for(int i = 0; i < k; ++i){
        string s; long long b; cin >> s >> b;
        hashpairs hashes = hashfn(s);
        dict.insert({hashes, -b});
    } 

    long long best_singleton = 0;
    // pair up
    long long ans = 0;
    auto it = dict.begin(); 
    while(it != dict.end()){
        auto [hp, b] = *it;
        it = dict.erase(it);
        hashpairs hprev = {{hp.first.second, hp.first.first}, {hp.second.second, hp.second.first}};
        auto it2 = dict.lower_bound({hprev, -1e6});
        auto it2p = *it2;
        bool suitable_pair = true;
        if(it2 == dict.end()){
            suitable_pair = false; 
        }
        else if(hprev == it2p.first){
            if(b + it2p.second < 0){
                ans += b + it2p.second;
                if(hp.first.first == hp.first.second) best_singleton = min(best_singleton, min(-b, -it2p.second)); //can unmatch to gain it2p.second or b;
            }
            else suitable_pair = false; 
            dict.erase(it2);

        }
        else{ 
            suitable_pair = false; 
        }

        it = dict.begin();
        if(suitable_pair) continue; 
        if(hp.first.first == hp.first.second) best_singleton = min(best_singleton, b);
    }
    cout << -(ans + best_singleton) << "\n";
    return 0;
}