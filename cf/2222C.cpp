/*
2222C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std; 

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<long long> a(n), sorted;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
    
        long long tgt;
        sorted = a; sort(sorted.begin(), sorted.end());
        tgt = sorted[n/2];

        vector<long long> dp(n+1, -1);
        dp[n] = 0;

        for(int i = n-1; i >= 0; i--) {
            int lt, gt, eq;
            lt = gt = eq = 0;
            for(int j = i; j < n; j++) {
                if (a[j] == tgt) ++eq;
                else if (a[j] < tgt) ++lt;
                else ++gt;
                if (dp[j+1] == -1) continue;
                if(((j-i+1) % 2) && abs(lt - gt) < eq) {
                    dp[i] = max(dp[i], 1 + dp[j+1]);
                }
            }
        }

        cout << dp[0] << "\n";
    }
    return 0;
}