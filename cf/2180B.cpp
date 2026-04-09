/*
2180C
*/

#include <iostream>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string head; string ans;
        cin >> head; ans = head;
        for(int i = 1; i < n; ++i) {
            string in; cin >> in;
            string nans1 = in; nans1.append(ans);
            string nans2 = ans; nans2.append(in);
            if(nans1 < nans2) {
                ans = nans1;
            }
            else ans = nans2;
            
        }
        cout << ans << "\n";
        cout << "\n";
    }
    return 0;
}