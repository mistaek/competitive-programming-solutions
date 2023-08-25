/*
1850G
AC
*/

#include <iostream>
#include <map>

using namespace std; 

int main(){
    int t; cin >> t; 

    while(t--){
        int n; cin >> n; 
        map<int, long long> xx, yy;
        map<pair<int, int>, long long> xy, yx;
        for(int i = 0; i <n ;i++){
            int x, y; cin >> x >> y;
            xx[x]++; yy[y]++; 
            xy[{0, y-x}]++;
            yx[{0, y+x}]++;
        }
        long long ans = 0; 
        for(auto x : xx){
            ans += (x.second * (x.second -1LL));
        }
        for(auto x : yy){
            ans += (x.second * (x.second -1LL));
        }
        for(auto x : xy){
            ans += (x.second * (x.second -1LL));
        }
        for(auto x : yx){
            ans += (x.second * (x.second -1LL));
        }
        cout << ans <<"\n";
    }
    return 0;
}