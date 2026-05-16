/*
2228A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //while(test()); 
    //return 0;
    int t; cin >> t;
    while(t--) {
        unsigned long long a;
        int n;
        cin >> a >> n;

        bool present[10] = {};
        int sD = 9, mD = 0;
        for(int i = 0; i < n; ++i) {
            char c; cin >> c;
            sD = min(c - '0', sD);
            mD = max(c - '0', mD);
            present[c-'0'] = true;
        }
        unsigned long long ans = 1e18;

        vector<int> digits;
        {
            bool exact = true;
            unsigned long long copy = a;
            do {
                if(present[copy % 10] == false) exact = false;
                digits.push_back(copy % 10);
                copy /= 10;
            } while (copy);
            if(exact == true) ans = 0;
        }
        reverse(digits.begin(), digits.end());
        {
            unsigned long long largerMagnitude = 0;
            unsigned long long powten = 1;
            while (true) {
                for(int i = 0; i < 10; ++i) {
                    if (i == 0 && largerMagnitude == 0) continue;
                    if (present[i]) {
                        largerMagnitude += i;
                        break;
                    }
                }
                // may not be able to make anything bigger
                if (largerMagnitude == 0) break;

                if (largerMagnitude/powten && a/powten == 0) break;
                largerMagnitude *= 10;
                powten *= 10;
            }
            if (largerMagnitude > a) ans = min(ans, largerMagnitude - a);
        }

        {
            unsigned long long lowerMag = 1e18, powten = 1;
            while (true) {
                if(a / (powten * 10) == 0) break;
                if (lowerMag == 1e18) lowerMag = 0;
                for (int i = 9; i >= 0; --i) {
                    if (present[i]) {
                        lowerMag *= 10;
                        lowerMag += i;
                        break; 
                    }
                }
                powten *= 10;
            }
            if (lowerMag < a) {
                ans = min(ans, a - lowerMag);
            }
        }

        // digit fandangling: smallest number which is >
        {
            unsigned long long num = 0;
            for(size_t i = 0; i < digits.size(); ++i) {
                num *= 10;
                int d = digits[i];
                // must go bigger
                for(int j = d+1; j < 10; ++j) {
                    if (present[j]) {
                        auto copy = num;
                        copy += j;
                        for(size_t ii = i+1; ii < digits.size(); ++ii){ 
                            copy *= 10;
                            copy += sD;
                        }
                        if (copy > a) ans = min(ans, copy-a);
                        break;
                    }
                }
                if(!present[d]) break;
                num += d;
            }
        }

         // digit fandangling: biggest number which is <
        {
            unsigned long long num = 0;
            for(size_t i = 0; i < digits.size(); ++i) {
                num *= 10;
                int d = digits[i];
                // must go smaller
                for(int j = d-1; j >= 0; --j) {
                    if (present[j]) {
                        auto copy = num;
                        copy +=j;
                        for(size_t ii = i+1; ii < digits.size(); ++ii) {
                            copy *= 10;
                            copy += mD;
                        }
                        if(copy < a) ans = min(ans, a- copy);
                        break;
                    }
                }
                if(!present[d]) break;
                num += d;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}