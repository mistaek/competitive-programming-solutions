/*
2231C
*/

#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

long long op (long long n){
    if (n % 2) return n+1;
    else return n/2;
}

int main() {
    int t; cin >> t;
    while (t--) {
        srand(time(nullptr));
        int n;
        cin >> n;
        
        map<long long, long long> a;
        for (int i = 0; i < n; ++i) {
            int ai;
            cin >> ai;
            //ai = rand() % 100 + 1;
            //og[i] = ai;

            a[ai]++;
        }

        long long ans = 0;
        
        long long lowcap = a.begin()->first;
        if(lowcap % 2) ++lowcap;
        while (prev(a.end())->first > lowcap) {
            auto [kk, cnt] = *prev(a.end());
            a.erase(prev(a.end()));

            long long k = kk;
            long long ops = 0;
            while (k > lowcap) {
                k = op(k);
                ++ops;
            }
            //cout << "Turned " << cnt << " copies of " << kk << " into " << k << " adding " << ops*cnt << " to the answer\n";

            ans += ops * cnt;
            a[k] += cnt;
            lowcap = a.begin()->first;
            if(lowcap % 2) ++lowcap;
            //cout << "Lowcap updated to " << lowcap << "\n";
        }

        
        if (a.size() == 2) {
            if (a.begin()->first == 1) ans += min(a.begin()->second, prev(a.end())->second);
            else ans += a.begin()->second;
        }

        /*
        int bf = 1e9;
        for(int i = 1; i <= 100; ++i) {
            int local = 0;
            for(int j = 0; j < n; ++j) {
                int x = og[j];
                while(x != i) {
                    if (x < i-1) {
                        local = 1e9; break;
                    }
                    x = op(x);
                    ++local;
                }
                if (local == 1e9) break;
            }
            bf = min(local, bf);
        }

        if (bf != ans) {
            cout << n << "\n";
            for(int i = 0; i < n; ++i) {
                cout << og[i] << " ";
            }
            cout << "\n";
            cout << bf << " " << ans << "\n";
            return 0;
        }
        if (t % 10000 == 0) cout << "OK " << t << "\n";
        */
        
        cout << ans << "\n";

    }
    return 0;
}