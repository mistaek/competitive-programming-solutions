/*
1153A
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    int n, t; cin >> n >> t; 
    
    int cur = 0, soonest = 1e9;
    auto upd = [&](int i, int ti){
        if(ti - t < soonest - t){
            cur = i; soonest = ti;
        }
    };
    for(int i = 0; i < n; ++i){
        //find first s + xd > t
        int s, d; cin >> s >> d; 
        if(s >= t){
            upd(i, s); 
            continue; 
        }

        int x = t + ((d - ((t-s) % d)) % d);
        //cout << x << "\n";
        upd(i, x); 
    }

    cout << cur + 1 << "\n";
    return 0;
}