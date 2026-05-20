/*
2230B
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    srand(time(nullptr));
    int t; cin >> t;
    while(t--) {
        string s;
        cin >> s;
        /*
        for(int i = 0; i < 5; ++i) {
            s.push_back('0' + (rand() % 4) + 1);
        }
        //*/
        int n = s.length();
        long long ans = 0;
        vector<int> nextOdd(n+1, n);
        vector<int> twoSuf(n+1, 0);

        // start with all odd string
        for(int i = 0; i < n; ++i) {
            if (s[i] == '4' || s[i] == '2') ++ans;
        }

        // nextOdd[i] = index of next odd number >= i
        // twoSuf[i] = number of twos in [i, n]
        for (int i = n-1; i >= 0; --i) {
            nextOdd[i] = nextOdd[i+1];
            if (s[i] == '3' || s[i] == '1') nextOdd[i] = i;
        }

        for(int i = n-1; i >= 0; --i) {
            twoSuf[i] = twoSuf[i+1];
            if (s[i] == '2') ++twoSuf[i];
        }

        long long cur = 0;
        // base = string if we remove ALL even numbers
        long long base = ans;
        //cout << base << "\n";
        for(int i = 0; i < n; ++i) {
            if (s[i] == '3' || s[i] == '1') {
                ++cur; 
            }
            //cout << "Remove " << cur << " to save " << twoSuf[0] <<"-" << twoSuf[nextOdd[i+1]] <<"=" << twoSuf[i]-twoSuf[nextOdd[i+1]]<< "\n";
            ans = min(ans, base + cur - (twoSuf[0] - twoSuf[nextOdd[i+1]]));
        }

        cout << ans << "\n";
    }
    return 0;
}