/*
2222B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<long long> a(n), x(m);
        vector<long long> odd, even;
        long long sum = 0; 
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            sum += a[i];
            if((i+1) % 2) odd.push_back(a[i]);
            else even.push_back(a[i]);
        }
        for(int i = 0; i < m; ++i) cin >> x[i];

        bool evenpopped = false, oddpopped = false;
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());

        for(int i = 0; i < m; ++i) {
            if(x[i] % 2) {
                if(odd.empty()) continue;
                if(odd.back() < 0 && oddpopped) continue;
                sum -= odd.back();
                odd.pop_back();
                oddpopped = true;
            }
            else {
                if(even.empty()) continue;
                if(even.back() < 0 && evenpopped) continue;
                sum -= even.back();
                even.pop_back();
                evenpopped = true;
            }
        }
        cout << sum << "\n";
    }
    return 0;
}