/*
1016E
AC, HATE DOUBLES
*/

#include <iostream>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    long long sy, a, b; cin >> sy >> a >> b; 
    int n; cin >> n; 
    pair<long long, long long> lr[n]; 
    for(int i = 0; i < n; ++i){
        cin >> lr[i].first >> lr[i].second;
    }

    sort(lr, lr+n);
    map<long long, long long> covered; 
    long long cur = 0;
    for(int i = 0; i < n; ++i){
        covered[lr[i].first] = -cur; 
        cur += lr[i].second - lr[i].first; 
        covered[lr[i].second] = cur; 
    }

    int q; cin >> q; 
    cout << fixed << setprecision(9);
    for(int i = 0; i < q; ++i){
        long long x, y; cin >> x >> y; 
        double left = (double)(-sy * (x - a))/(y - sy) + a; 
        double right = (double)(-sy *(x - b))/(y-sy) + b; 
        double num = 0, denom = (right - left);


        auto it1 = covered.upper_bound((long long)left);
        if(it1 != covered.begin()){
            it1 = prev(it1); 
            num -= abs(it1->second); 
            if(it1->second <= 0){ // in interval
                num -= max(0.0, left - it1->first);
            }
        }

        //cout << left << " " << right << "\n";
        //cout << it1->first << " " << it1->second << " " << num << "\n";

        it1 = covered.upper_bound((long long)right);
        if(it1 == covered.end()) it1 = prev(it1); 
        num += abs(it1->second);
        if(it1->second > 0){
            num -= max(0.0, it1->first - right); 
        }
        
        //cout << it1->first << " " << it1->second << " " << num << "\n";

        //cout << num << " " << denom << " " << num/denom << "\n";
        cout << (num/denom) * (double)(b-a) << "\n";
    }


    return 0;
}
