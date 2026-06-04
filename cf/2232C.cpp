/*
2232C1/C2
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) {
        long long n, x, s;
        cin >> n >> x >> s;

        vector<int> types(n);
        for(int i = 0; i < n; ++i) {
            char c; cin >> c;
            if (c == 'I') types[i] = 0;
            else if (c == 'E') types[i] = 1;
            else types[i] = 2;
        }

        vector<long long> sufI(n, 0);
        for(int i = n-1; i >= 0; --i) {
            if (types[i] == 0) ++sufI[i];
            if (i < n-1) sufI[i] += sufI[i+1]; 
        }

        vector<long long> extroB4AI(n, 0);
        for(int i = n-1; i >= 0; --i) {
            if (i < n-1) extroB4AI[i] += extroB4AI[i+1];
            if (types[i] == 1) ++extroB4AI[i];
            else extroB4AI[i] = 0;
        }

        long long eT = x, oT = 0;
        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            //cout << eT << " " << oT << "\n";
            if (types[i] == 0) {
                if (eT) {
                    --eT;
                    oT += s-1;
                    ++ans;
                }
            }
            else if (types[i] == 1) {
                if (oT) {
                    --oT;
                    ++ans;
                }
            }
            else if (types[i] == 2) {
                // can sit on a new table or an open slot
                // sit on the one which causes the least loss (should be greedyable?)
                long long eTL = 1e9, oTL = 1e9;
                if (eT) {
                    // if more introverts than empty tables, we will take one of their spots with this ambivert
                    if (sufI[i] >= eT) eTL = 1;
                    else eTL = 0;
                }
                if (oT) {
                    // have extroB4AI[i] extroverts before the next ambi/intro
                    // if these outnumber the current number of open tables, we will lose that many
                    if (i == n-1) oTL = 0;
                    else oTL = max(0LL, extroB4AI[i+1] + 1 - oT);
                }

                if (eTL == 1e9 && oTL == 1e9) continue;
                ++ans;
                //cout << eTL << " " << oTL << "\n";
                if (eTL <= oTL) {
                    --eT;
                    oT += s-1;
                    //cout << "Ambivert " << i << " seated at empty\n";
                }
                else {
                    //cout << "Ambivert " << i << " seated at open\n";
                    --oT;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}