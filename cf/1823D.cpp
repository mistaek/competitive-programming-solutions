/*
1823D
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k;
        vector<int> x(k), c(k); 
        for(int i = 0; i < k; ++i) cin >> x[i];
        for(int i = 0; i < k; ++i) cin >> c[i];

        if(x[k-1] != n){
            x.push_back(n);
            c.push_back(c[k-1]);
        }
        int curchar = 2, curcnt = 3, i = 3, qi = 0;
        string out = "abc"; 
        bool pos = true; 
        while(i < n){
            if(c[qi] > x[qi]) pos = false;
            if(qi && c[qi] - c[qi-1] > x[qi] - x[qi-1]) pos = false; 
            if(!pos) break;  
            while(curcnt < c[qi]){
                out.push_back('a' + curchar); 
                ++i; 
                ++curcnt; 
            }

            while(i < x[qi]){
                ++curchar; 
                curchar %= 3; 
                out.push_back('a' + curchar); 
                ++i; 
            }
            ++qi; 
        }
        if(pos) cout << "YES\n" << out << "\n"; 
        else cout << "NO\n";
    }
    return 0;
}