/*
2178D
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        vector<pair<long long, long long>> a(n);

        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i+1;
        }
        sort(a.begin(), a.end());
        if(m > n/2) {
            cout << "-1\n";
            continue;
        }
        if (m == 0) {
            long long sum = 0;
            for(int i = 0; i < n-1; ++i) sum += a[i].first;
            if(sum < a[n-1].first) {
                cout << "-1\n"; continue;
            }
            cout << n-1 << "\n";
            for(int i = 0; i < n-1; ++i) {
                if(sum - a[i].first >= a[n-1].first){
                    cout << a[i].second << " " << a[i+1].second << "\n";
                    sum -= a[i].first;
                }
                else cout << a[i].second << " " << a[n-1].second << "\n";
            }
        }
        else {
            cout << n-m << "\n";
            for(int i = 0; i < n - 2*m; ++i){
                cout << a[i].second << " " << a[i+1].second << "\n";
            }
            for(int i = n-2*m + 1; i < n; i+=2) {
                cout << a[i].second << " " << a[i-1].second << "\n";
            }
        }
    }
    return 0;
}