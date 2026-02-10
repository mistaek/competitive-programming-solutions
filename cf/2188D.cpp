/*
2188C
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--) {
        long long x, y; cin >> x >> y;
        long long ansp = x, ansq = y;
        long long best = 1e15, p = 0, q = 0;
        for(int i = 30; i >= 0; --i) {
            if((x & (1 << i)) && (y & (1 << i))) {
                long long flipx = 0, flipy = 0;
                long long ans1 = 1e15, ans2 = 1e15;
                bool flipped = false;
                for(int j = i; j <= 30; ++j) {
                    if (!flipped && (ansp & (1 << j)) == 0) {
                        flipped = true;
                        flipx |= (1 << j);
                    }
                    else if(flipped && (ansp & (1 << j))) flipx |= (1 << j);
                }
                if((flipx & ansq) == 0) ans1 = abs(x - flipx) + abs(y - ansq);

                flipped = false;
                for(int j = i; j <= 30; ++j) {
                    if (!flipped && (ansq & (1 << j)) == 0) {
                        flipped = true;
                        flipy |= (1 << j);
                    }
                    else if(flipped && (ansq & (1 << j))) flipy |= (1 << j);
                }
                if((flipy & ansp) == 0) ans2 = abs(x - ansp) + abs(y - flipy);

                if(ans1 < best) {
                    best = ans1;
                    p = flipx;
                    q = ansq;
                }
                if(ans2 < best) {
                    best = ans2;
                    p = ansp;
                    q = flipy;
                }

                // drop
                long long ans3 = 1e15;
                ansp -= (1 << i);
                for(int j = i-1; j >= 0; --j) {
                    if(ansp & (1 << j) && ansq & (1 << j)) ansp -= (1 << j);
                    else if((ansq & (1 << j)) == 0) ansp |= (1 << j);
                }
                if(ans3 < best) {
                    best = ans3; 
                    p = ansp;
                    q = ansq;
                }
                break;
            }
        }

        if(abs(x - ansp) + abs(y - ansq) < best) {
            p = ansp;
            q = ansq;
        }
        cout << p << " " << q << "\n";
    }
    return 0;
}