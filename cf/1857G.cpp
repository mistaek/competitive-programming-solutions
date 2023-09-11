/*
1857G
*/

//where is bug?
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

long long mod = 998244353;

long long binexp(long long a,long long n)
{
    if(n==0)return 1;
    if(n%2==0)return binexp(a*a%mod,n/2);
    else return a*binexp(a,n-1)%mod;
}

class UFDS{
    vector<long long> s, sz; 
    public:
        UFDS(long long n){
            for(long long i = 0; i <= n; i++){
                s.emplace_back(i);
                sz.emplace_back(1);  
            }
        }
        long long find(long long v){
            if(s[v]==v)return v;
            else return s[v]=find(s[v]);
        }
        long long ssz(long long a){
            return sz[find(a)]; 
        }
        void join(long long a, long long b){
            a = find(a); 
            b = find(b); 
            s[a] = b; 
            sz[b] += sz[a];         
        }

};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0); 
    long long t; cin >> t; 
    while(t--){
        long long n, S; cin >> n >> S; 
        vector<pair<long long, pair<long long, long long>>> el(n-1); 
        for(long long i = 0; i < n-1; i++){
            cin >> el[i].second.first >> el[i].second.second >> el[i].first; 
        }
        sort(el.begin(), el.end()); 
        UFDS dsu(n); 

        long long ans = 1; 
        for(long long i = 0; i < n-1; i++){
            long long sub_u = dsu.ssz(el[i].second.first); 
            long long sub_v = dsu.ssz(el[i].second.second);
            long long pow = S - el[i].first + 1;
            long long exp = 1LL*sub_v * sub_u - 1LL;   
            ans *= binexp(pow, exp); 
            ans %= mod; 
            dsu.join(el[i].second.first, el[i].second.second); 
        }
        cout << ans << "\n";
    }

    return 0;
}