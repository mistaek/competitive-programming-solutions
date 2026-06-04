/*
2208C
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<double> c(n), p(n), dp(n+1, 0);

        for (int i = 0; i < n; ++i) {
            cin >> c[i] >> p[i];
        }

        for(int i = n-1; i >= 0; --i) {
            dp[i] = max(dp[i+1], dp[i+1] * ((100.0 - p[i]) / 100.0) + c[i]);
        }

        cout << std::fixed << std::setprecision(std::numeric_limits<double>::max_digits10) << dp[0] << "\n";
    }
    return 0;
}