/*
1902D
AC
*/

#include <iostream>
#include <map>
#include <vector>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0); 
    int n, q; cin >> n >> q; 
    map<pair<int, int>, vector<int>> p; 
    p[{0, 0}].push_back(0); 
    pair<int, int> a[n+1] = {{0, 0}};
    int cx = 0, cy = 0;
    for(int i = 1; i <= n; i++){
        char cmd; cin >> cmd; 
        if(cmd == 'U') cy++; 
        if(cmd == 'D') cy--;
        if(cmd == 'R') cx++;
        if(cmd == 'L') cx--; 
        a[i] = {cx, cy};
        p[{cx, cy}].push_back(i); 
    }

    for(int i = 0; i < q; i++){
        int x, y, l, r; cin >> x >> y >> l >> r; 
        auto it = p.find({x, y});
        if(it != p.end()){
            if(it->second[0] < l || it->second.back() >= r){
                cout << "YES\n"; 
                continue; 
            }
        }
        //cout << "Start: " << a[l].first << " " << a[r].first << ", End: "<< a[r].first << " " << a[r].second << "\n";
        //cout << x << " " << y << " visited iff "; 
        x = a[l-1].first + a[r].first - x, y = a[l-1].second + a[r].second - y; 
        it = p.find({x, y}); 
        //cout << x << " " << y << " is visited\n";
        if(it!= p.end()){
            auto pos = lower_bound(it->second.begin(), it->second.end(), l);
            
            if(pos != it->second.end() && *pos <= r){
                cout << "YES\n"; 
            }
            else cout << "NO\n";
        } 
        else cout << "NO\n";
    }
    return 0;
}