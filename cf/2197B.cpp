/*
2197B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> p(n), a(n), pos(n+1, -1);
        for(int i = 0; i < n; ++i) {
            cin >> p[i];
            pos[p[i]] = i;
        }
        for(int i = 0; i < n; ++i) cin >> a[i];

        
        vector<bool> appeared(n+1, false);
        bool possible = true;
        int last = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] != last) {
                if(pos[last] > pos[a[i]]){
                    possible = false; break;
                }
                if(appeared[a[i]]){
                    possible = false; break;
                }
                appeared[last] = true;
                last = a[i];
            }
        }

        if(possible) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}