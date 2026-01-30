/*
1181D
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;
vector<int> freq;
vector<vector<int>> freqfreq;
vector<int> st;

// insert j = k into the tree
void insert(int i, int j, int ql, int qr) {
    while(ql != qr){
        st[i]++; // sum of current node
        int m = (ql + qr)/2;
        if(j <= m){
            i = i+1;
            qr = m;
        }
        else {
            i = i + 2*(m-ql + 1);
            ql = m+1;
        }
    }
    // last node with ql == qr == j
    st[i] = 1;
}

// returns first index at which sum >= x
int query(int i, int l, int r, int x) {
    if (st[i] < x) {
        return -1;
    }
    while(l != r) {
        int m = (l+r)/2;
        if(st[i+1] >= x) {
            i+=1;
            r = m;
        }
        else {
            x -= st[i+1];
            i += 2*(m-l+1);
            l = m+1;
        }
    }
    return l;
}

int main() {
    int n, m, q; cin >> n >> m >> q;

    freq = vector<int>(m+1, 0);
    freqfreq = vector<vector<int>>(n+1);
    st = vector<int>(2*(m+1), 0);

    freq[0] = numeric_limits<int>::max();

    for (int i = 0; i < n; ++i){
        int a; cin >> a;
        freq[a]++;
    }

    long long minf = *min_element(freq.begin(), freq.end());
    for(int& e : freq) e-=minf;

    for (int i = 1; i <= m; ++i) {
        freqfreq[freq[i]].push_back(i);
    }

    vector<long long> clen(n+1, 0);
    vector<pair<long long, int>> queries(q);
    vector<int> ans(q, 0);
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].first;
        queries[i].second = i;
    }

    sort(queries.begin(), queries.end());

    long long cur = 0; // current number of elements which appear
    for(int i = 1; i <= n; ++i){
        clen[i] = clen[i-1];
        cur += freqfreq[i-1].size(); // all elements with freq < i will appear on the i-th cycle
        clen[i] += cur;
        //cout << "cycle " << i << " ends on " << clen[i] << "\n";
    }

    int previd = 0;
    for(int i = 0; i < q; ++i) {
        long long y = queries[i].first;
        auto it = lower_bound(clen.begin(), clen.end(), y-n);

        int idx = it - clen.begin();
        while(idx != previd){
            //cout << "Inserting " << freqfreq[previd].size() << " elements of frequency " << previd << "\n";
            if(previd <= n) for(auto mv : freqfreq[previd]) insert(0, mv, 0, m);
            previd++;
        }
        long long pos = y - n - clen[idx-1]; // positions are 1-indexed
        pos %= m; if(pos == 0) pos = m;
        ans[queries[i].second] = query(0, 0, m, pos);

        //cout << "Position " << pos << " of cycle " << idx << " is " << ans[queries[i].second] << "\n";
        //cout << st[0] << "\n";
    }

    for(int i = 0; i < q; ++i) cout << ans[i] << "\n";
    return 0;
}