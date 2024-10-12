/*
939E
AC
*/

#include <iostream>
#include <set>
#include <algorithm>
#include <iomanip>
using namespace std; 
multiset<int> ms; 
long long curs = 0, cursz = 0, curmax = 0;
double ans = 0;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q; cin >> q; 
   
    while(q--){
        int qt; cin >> qt; 
        if(qt == 1){
            long long v; cin >> v; 
            if(v > curmax){
                if(curmax) ms.insert(curmax); 
                curmax = v;
                ans = (double)curmax - (double)(curs + curmax)/(cursz + 1);
            }
            else ms.insert(v);
            auto it = ms.begin(); 
            while(it != ms.end()){
                auto nv = *it; 
                double newans = (double)curmax - static_cast<double>((curs + nv + curmax))/(cursz + 2); 
                if(newans >= ans){
                    curs += nv; 
                    ++cursz; 
                    ans = newans; 
                    it = ms.erase(it);
                }
                else break; 
            }
        }
        else {
            cout << std::fixed << setprecision(10) <<  ans << "\n";
        }
    }
    return 0;
}