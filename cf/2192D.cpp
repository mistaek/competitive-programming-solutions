/*
2192D
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n, 0);
        vector<vector<int>> g(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n-1; ++i) {
            int u, v; cin >> u >> v;
            --u; --v; 
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector<long long> subtSum(n, 0), base(n, 0), ans(n, 0), depth(n, 0), maxDepth(n, 0), delta(n, 0);
        auto solve = [&](auto self, int u, int p) -> void {
            // if(u == 1) cout << "CONSIDERING " << u << "\n";
            if(p != u) {
                depth[u] = depth[p]+1;
                maxDepth[u] = max(depth[u], maxDepth[u]);
            }

            subtSum[u] += a[u];
            int biggest = -1, second = -1;
            for(auto c : g[u]) {
                if(c == p) continue;
                self(self, c, u);
                maxDepth[u] = max(maxDepth[u], maxDepth[c]);
                subtSum[u] += subtSum[c];
                base[u] += base[c] + subtSum[c];
                if(maxDepth[c] >= biggest) {
                    second = biggest;
                    biggest = maxDepth[c];
                }
                else if(maxDepth[c] >= second) {
                    second = maxDepth[c];
                }
                // if(u == 1) cout << "Considering child " << c << "\n" << "base: " << base[c] << "\n" << "subtS: " << subtSum[c] << "\n";
            }
            ans[u] = base[u];
            // if(u == 1) cout << "Initial base: " << base[u] << "\n";

            if(second != -1) {
                // if(u == 1) cout << "Considering depths " << biggest << " " << second << "\n";
                for(auto c : g[u]) {
                    if(c == p) continue;
                    // try swapping onto other subtree
                    // if(u == 1) cout << "Swapping " << c << "\n";
                    if(maxDepth[c] == biggest) {
                        long long localans = base[u] + subtSum[c] * (second - depth[u]); 
                        // if(u == 1) cout << "Localans 1: " << localans << "\n";
                        if(localans > ans[u]) {
                            ans[u] = localans;
                            delta[u] = subtSum[c] * (second - depth[u]);
                        }
                    }
                    else {
                        long long localans = base[u] + subtSum[c] * (biggest - depth[u]);
                        // if(u == 1) cout << "Localans 2: " << localans << "\n";
                        if(localans > ans[u]) {
                            ans[u] = localans;
                            delta[u] = subtSum[c] * (biggest - depth[u]);
                        }
                    }
                }
            }

            // if(u == 1) cout << "Considering inner swaps: " << "\n";
            for(auto c : g[u]) {
                if(c == p) continue;
                // try inner swap
                long long localans = base[u] + delta[c];
                // if(u == 1) cout << "Localans: " << localans << "\n";
                if(localans > ans[u]) {
                    ans[u] = localans;
                    delta[u] = delta[c];
                }
            }
        };
        solve(solve, 0, 0);
        for(int i = 0; i < n; ++i) {
            if(i) cout << " ";
            cout << ans[i];
        }
        cout << "\n";
    }
    return 0;
}