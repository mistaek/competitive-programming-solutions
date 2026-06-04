/*
2208D
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<bool>> reachable, fwd;
vector<int> p, reachablecntmp;
vector<pair<int, int>> reachablecnt, e;
vector<vector<int>> rg;
int edges = 0;
bool pos = true;
int n;

// create edges for node u
void place(int u) {
    vector<bool> done(n, 0);
    done[u] = 1;
    int i = reachablecntmp[u] - 1;
    for (; i >= 0; --i) {
        int v = reachablecnt[i].second;
        if (done[v] || !reachable[u][v]) continue;
        //cout << "Placing " << u+1 << " can reach " << v+1 << "\n";
        for (int j : rg[v]) {
            if (reachable[v][j] && !reachable[u][j]) {
                pos = false; break;
            }
            // already can reach j from another branch
            // believe this should be impossible since we are descending in order of size
            if (reachable[v][j] && done[j]) {
                //cout << "Placing " << u << " " << j << " already done\n";
                pos = false; break;
            }

            if (reachable[v][j]) {
                done[j] = true;
            }
        }
        if (!pos) return;
        ++edges;
        if (edges > n-1) {
            pos = false; return;
        }
        e.push_back({u+1, v+1});
        fwd[u][v] = 1;
        p[v] = u;
    }

    for (int i = 0; i < n; ++i) {
        if (reachable[u][i] && !done[i]) {
            pos = false; return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--){
        cin >> n;
        pos = true;
        rg = vector<vector<int>>(n);
        reachable = fwd = vector<vector<bool>>(n, vector<bool>(n, false));
        reachablecnt = vector<pair<int, int>>(n, {0, 0});
        p = reachablecntmp = vector<int>(n, -1);
        e.clear();
        edges = 0;
        for (int i = 0; i < n; ++i) {
            reachablecnt[i].second = i;
            for (int j = 0; j < n; ++j) {
                char c; cin >> c;
                reachable[i][j] = (c == '1');
                reachablecnt[i].first += (c == '1');
                if (i == j && !reachable[i][j]) {
                    //cout << i << " " << j << " " << c << "\n";
                    pos = false;
                }
                if (reachable[i][j]) rg[i].push_back(j);
            }
        }

        if (!pos) {
            //cout << "Some guy cannot reach themselves\n";
            cout << "NO\n";
            continue;
        }
        
        sort(reachablecnt.begin(), reachablecnt.end());
        for(int i = 0; i < n; ++i) reachablecntmp[reachablecnt[i].second] = i;
        for (int i = 0; i < n; ++i) {
            place(reachablecnt[i].second);
            if (!pos) break;
        }

        if (edges != n-1) pos = false;

        // traverse the graph once to see if it's connected
        vector<bool> vis(n, false);
        queue<int> bfs;
        bfs.push(0);
        vis[0] = true;
        while(!bfs.empty()) {
            int u = bfs.front(); bfs.pop();

            for (int i = 0; i < n; ++i) {
                if (vis[i]) continue;
                if (fwd[u][i] || fwd[i][u]) {
                    vis[i] = true;
                    bfs.push(i);
                }
            }
        }

        for(int i = 0; i < n; ++i) {
            if (!vis[i]) pos = false;
        }

        if (!pos) {
            cout << "NO\n";

            //for (auto [u, v] : e) cout << u << " " << v << "\n";
        }
        else {
            cout << "YES\n";
            for (auto [u, v] : e) {
                cout << u << " " << v << "\n";
            }
        }
    }
    return 0;
}