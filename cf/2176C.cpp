/*
2176C
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<long long> odd, even;
        for(int i = 0; i < n; ++i) {
            int a; cin >> a;
            if(a%2) odd.push_back(a); 
            else even.push_back(a);
        }

        sort(odd.begin(), odd.end(), greater<long long>());
        sort(even.begin(), even.end(), greater<long long>());

        int neven = even.size();
        vector<long long> pref(neven+1, 0);
        for(int i = 1; i <= neven; ++i) {
            pref[i] += pref[i-1];
            pref[i] += even[i-1];
        }

        if(odd.size() == 0) {
            for(int i = 0; i < n; ++i) {
                if(i) cout << " ";
                cout << 0;
            }
            cout << "\n";
            continue;
        }
        else {
            for(int k = 1; k <= n; ++k){
                if(k > 1) cout << " ";

                int eventakes = min(k-1, (int)even.size());
                int oddtakes = max(0LL, k-1 - (long long)even.size());
                if(oddtakes % 2 == 0) cout << odd[0] + pref[eventakes];
                else {
                    if(eventakes > 0 && (int)odd.size() > oddtakes + 1 ) cout << odd[0] + pref[eventakes-1];
                    else cout << 0;
                }
            }
            cout << "\n";
        }
    }
    return 0;
}