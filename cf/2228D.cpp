/*
2228D
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t; 
    while(t--) {
        int n; cin >> n;
        vector<pair<int, int>> ptsByX(n), ptsByY(n);
        for(int i = 0; i < n; ++i) {
            int x, y; cin >> x >> y;
            ptsByX[i] = {x, y};
            ptsByY[i] = {y, x};
        }

        vector<long long> distinctY(n, 0);
        distinctY[0] = 1;
        sort(ptsByX.begin(), ptsByX.end());
        sort(ptsByY.begin(), ptsByY.end());

        for(int i = 1; i < n; ++i) {
            distinctY[i] = distinctY[i-1] + (ptsByY[i].first != ptsByY[i-1].first);
        }

        vector<long long> rightMins(n), rightMaxs(n);

        for (int i = n-1; i>=0; --i) {
            rightMins[i] = ptsByX[i].second;
            rightMaxs[i] = ptsByX[i].second;
            if (i < n-1) rightMins[i] = min(rightMins[i], rightMins[i+1]);
            if (i < n-1) rightMaxs[i] = max(rightMaxs[i], rightMaxs[i+1]);
        }

        int i = 0, curX = ptsByX[0].first;
        int leftMin = 1e9, leftMax = 0;
        unsigned long long ans = 0;
        for(;;) {
            // everything < curX is moved to the left
            while(i < n && ptsByX[i].first == curX){
                auto [x, y] = ptsByX[i];
                leftMin = min(leftMin, y);
                leftMax = max(leftMax, y);
                ++i;
            }
            if(i == n) break;
            curX = ptsByX[i].first;

            int rightMin = rightMins[i], rightMax = rightMaxs[i];
        
            if(max(leftMin, rightMin) >= min(rightMax, leftMax)) continue;
            
            int it1 = lower_bound(ptsByY.begin(), ptsByY.end(), std::make_pair(max(leftMin, rightMin)+1, 0)) - ptsByY.begin()-1;
            int it2 = lower_bound(ptsByY.begin(), ptsByY.end(), std::make_pair(min(leftMax, rightMax), 0)) - ptsByY.begin() - 1;
            ans += distinctY[it2] - distinctY[it1] + 1;
        }
        cout << ans << "\n";
    }
    return 0;
}