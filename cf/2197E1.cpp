/*
2197E1
*/

#include <iostream>
#include <vector>

using namespace std; 

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<vector<int>> g(n+1);
        vector<int> paths(n+1, -1); // number of paths starting at x

        vector<int> prevPath, curPath;
        int curQuery = 1;
        auto close = [&](int u) {
            if(paths[u] != -1) return;
            paths[u] = 1;
            for(auto v : g[u]) paths[u] += paths[v];
        };

        bool outofEdges = false;
        for(int u = 1; u <= n; ++u) {
            if(paths[u] != -1) {
                // we already know everything downstream from i

                //cout << "Trying to learn about " << u << " at query " << curQuery << " but we know everything, jumping to " << curQuery + paths[u] << "\n";
                curQuery += paths[u]; // next vertex starts here presumably
                continue;
            }

            if(outofEdges) {
                close(u); continue;
            }
            // first path will be {u}
            prevPath = {u};
            ++curQuery;

            while(true) {
                cout << "? " << curQuery << endl;
                int q; cin >> q;
                if(q == 0) {
                    outofEdges = true;
                    close(u); break;
                }

                curPath = vector<int>(q);
                for(int i = 0; i < q; ++i) cin >> curPath[i];

                if(q > (int) prevPath.size()) {
                    // new edge at the end, can only increase by 1
                    g[curPath[q-2]].push_back(curPath[q-1]);
                    //cout << "Learned new edge " << curPath[q-2] << " " << curPath[q-1] << endl;
                }
                else {
                    if(q > 1) {
                        // new edge at the end of the path
                        g[curPath[q-2]].push_back(curPath[q-1]);
                        //cout << "Learned new edge " << curPath[q-2] << " " << curPath[q-1] << "\n";
                    }

                    for(int i = prevPath.size() - 1; i >= q-1; --i) {
                        close(prevPath[i]);
                        //cout << "Finished learning about " << prevPath[i] << " which has " << paths[prevPath[i]] << " paths" << endl;
                    }
                }

                prevPath = curPath;
                if(q > 1) {
                    // still learning about u, learned a new edge
                    if(paths[curPath.back()] != -1) {
                        //cout << "Know everything about tail, skipping\n";
                        curQuery += paths[curPath.back()];
                        //for(auto v : prevPath) cout << v << " ";
                        //cout << "\n";
                    }
                    else {
                        curQuery++; // continue learning about tail
                    }
                }
                // have closed the current one
                if(paths[u] != -1) break;
            }

        }

        int m = 0;
        for(int i = 1; i <= n; ++i) m += g[i].size();
        cout << "! " << m << endl;
        for(int i = 1; i <= n; ++i){
            for(auto j : g[i]) {
                cout << i << " " << j << "\n";
            }
        }
        cout.flush();
    }
    return 0;
}
