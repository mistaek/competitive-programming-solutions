/*
2230D
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    int x;
    //int ctr = 0;
    while(t--) {
        int n; cin >> n;
        vector<int> showA(n), showB(n);
        vector<set<int>> showingsA(n+1), showingsB(n+1);
        set<int> bad;
        for(int i = 0; i < n; ++i) {
            cin >> showA[i];
            showingsA[showA[i]].insert(i);
        }
        for(int i = 0; i < n; ++i) {
            cin >> showB[i];
            showingsB[showB[i]].insert(i);
        }

        /*
        if (ctr >= 5 && ctr != 874) continue;
        if (ctr == 874) {
            cout << n << "\n";
            for(int i = 0; i < n; ++i) cout << showA[i] << " ";
            for(int i = 0; i < n; ++i) cout << showB[i] << " ";
        }
        // */

        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            showingsA[i].insert(n);
            showingsB[i].insert(n);
        }
    
        int maxEp = 0;
        if (*showingsA[1].begin() != *showingsB[1].begin() || *showingsA[1].begin() == n) bad.insert(1);

        for(int i = 2; i <= n; ++i) {
            int prevDate = max(*showingsA[i-1].begin(), *showingsB[i-1].begin());

            while (*showingsA[i].begin() < prevDate) showingsA[i].erase(showingsA[i].begin());
            while (*showingsB[i].begin() < prevDate) showingsB[i].erase(showingsB[i].begin());

            if (*showingsA[i].begin() != *showingsB[i].begin() || *showingsA[i].begin() == n) bad.insert(i);
        }

        for(int i = 0; i < n; ++i) {            
            maxEp = (bad.empty()) ? n : *bad.begin() - 1;
            
            //cout << "maxEp is " << maxEp << "\n";
            if (maxEp == n) {
                ans += n - i;
            }
            else {
                int nextEp = maxEp + 1;
                int aMin = *showingsA[nextEp].begin() - 1;
                int bMin = *showingsB[nextEp].begin() - 1;

                /*
                cout << aMin << " " << bMin << "\n";
                cout << "L = " << i << " Any R <= " << min(aMin, bMin) << " is fine\n";
                cout << min(aMin, bMin) - i + 1 << " good intervals\n";
                // */
                if (min(aMin, bMin) >= i) {
                    ans += min(aMin, bMin) - i + 1;
                }
            }

            // Remove current episode
            for(int j = showA[i]; j <= n; ++j) {
                int prevDate = (j == showA[i]) ? i+1 : max(*showingsA[j-1].begin(), *showingsB[j-1].begin()); 
                if (*showingsA[j].begin() >= prevDate && *showingsB[j].begin() >= prevDate) break;

                while (*showingsA[j].begin() < prevDate) showingsA[j].erase(showingsA[j].begin());
                while (*showingsB[j].begin() < prevDate) showingsB[j].erase(showingsB[j].begin());

                if (*showingsA[j].begin() != *showingsB[j].begin() || *showingsA[j].begin() == n) bad.insert(j);
                else bad.erase(j);
            }

            for(int j = showB[i]; j <= n; ++j) {
                int prevDate = (j == showB[i]) ? i+1 : max(*showingsA[j-1].begin(), *showingsB[j-1].begin()); 
                if (*showingsA[j].begin() >= prevDate && *showingsB[j].begin() >= prevDate) break;
                while (*showingsA[j].begin() < prevDate) showingsA[j].erase(showingsA[j].begin());
                while (*showingsB[j].begin() < prevDate) showingsB[j].erase(showingsB[j].begin());

                if (*showingsA[j].begin() != *showingsB[j].begin() || *showingsA[j].begin() == n) bad.insert(j);
                else bad.erase(j);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}