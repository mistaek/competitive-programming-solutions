/*
2189B
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

int main() {
    int t; cin >> t; 
    while (t--) {
        int n; long long x; 
        cin >> n >> x;
        vector<long long> dist;

        for(int i = 0; i < n; ++i){
            long long a, b, c; cin >> a >> b >> c;
            x -= (b-1) * a;
            dist.push_back(b*a-c);
        }

        if(x <= 0) {
            cout << "0\n";
            continue;
        }
        sort(dist.begin(), dist.end(), greater<long long>()); 
        if(dist[0] <= 0) {
            cout << "-1\n";
        }
        else {
            long long ans = x/dist[0];
            if(x % dist[0]) ++ans;
            cout << ans << "\n";
        }
        
    }
    return 0;
}