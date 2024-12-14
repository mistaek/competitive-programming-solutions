/*
975D
ac geometry
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, a, b; cin >> n >> a >> b;
    map<long long, long long> nb;
    map<pair<long long, long long>, long long> repeated; //repeated pairs
    long long ans = 0; 
    for(int i = 0; i <n; ++i){
        long long x, vx, vy; cin >> x >> vx >> vy;

        long long b= vy - (a * vx);
        ++repeated[{vx, vy}];
        ++nb[b]; 

    }
    for(auto& [k, v] : nb){
        ans += v * (v-1);
    }
    for(auto& [k, v] : repeated){
        ans -= v * (v-1);
    }
    cout << ans << "\n";
    return 0;
}