/*
1843F1
AC, IO optimization doesn't work for this problem for some reason
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    int t; cin >> t; 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(t--){
        int n; cin >> n; 
        vector<int> s(2, 1), m(2, 0), bs(2, 1), ms(2, 0); 
        while(n--){
            char t; cin >> t; 
            if(t == '+'){
                int v, x; cin >> v >> x; 
                int curs, curm; 
                curs = max(0, s[v]+ x);
                curm = min(0, m[v] + x);
                s.push_back(curs); m.push_back(curm);
                bs.push_back(max(curs, bs[v]));
                ms.push_back(min(curm, ms[v]));
            }
            else if(t == '?'){
                int u, v, k; cin >> u >> v >> k;
                if(k <= bs[v] && k >= ms[v]) cout << "yes\n"; 
                else cout << "no\n";
            }
        }
    }
    return 0;
}