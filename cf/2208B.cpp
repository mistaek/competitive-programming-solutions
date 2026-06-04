/*
2208B
*/

#include <iostream>
#include <set>
#include <queue>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k, p, m; cin >> n >> k >> p >> m;
        int spent = 0, wc = 0;
        multiset<int> hand;
        queue<int> deck;
        for (int i = 0; i < n; ++i) {
            int cost; cin >> cost;
            if (i < k) hand.insert(cost);
            else deck.push(cost);
            if (i == p - 1) wc = cost;
        }

        int ans = 0;
        while (spent <= m) {
            if (p <= k) {
                if (m - spent < wc) break;
                else {
                    ++ans;
                    hand.erase(hand.find(wc));
                    deck.push(wc);
                    p = n;
                    int nc = deck.front(); deck.pop();
                    hand.insert(nc);
                    spent += wc;
                }
            }
            else {
                int c = *hand.begin();
                hand.erase(hand.begin());
                deck.push(c);
                int nc = deck.front(); deck.pop();
                hand.insert(nc);
                --p;
                spent += c;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}