/*
2232D
*/
 
#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std; 
 
struct mv {
    int id;
    int from;
    int to;
};
 
vector<int> a;
vector<mv> out;

void m (int l, int from, int to, int wk) {
    if (l == 0) return;
    if (l == 1) {
        out.push_back({l, from, to});
    }
    else {
        // in order to move l, we need to have a[l] on top
        // move 1..l- 1 - a[l]
        m(l - a[l-1] - 1, from, wk, to);
        out.push_back({l, from, to});
        if (a[l-1] != 0) {
            // move back
            m(l-a[l-1] - 1, wk, from, to);
            m(l-1, from, to, wk);
        }
        else {
            m(l-1, wk, to, from);
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        a = vector<int>(n);
        out.clear();
        bool pos = true;
        for(int i = 0; i < n; ++i){
            cin >> a[i];
            if (a[i] > i) pos = false;
        }
        if (!pos) {
            cout << "NO\n";
            continue;
        }
        m(n, 1, 3, 2);
        cout << "YES\n";
        cout << out.size() << "\n";
        for(size_t i = 0; i < out.size(); ++i) {
            cout << out[i].id << " " << out[i].from << " " << out[i].to << "\n";
        }
    }
    return 0;
}