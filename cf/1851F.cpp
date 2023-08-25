/*
1851F
ac
*/

#include <iostream>
#include <algorithm>

using namespace std; 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        long long n, k; cin >> n>> k; 
        pair<long long, int> a[n], origin[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i+1;  
            origin[i] = a[i];
        }

        sort(a, a+n);
        long long minimum = (1 << k);
        pair<int, int> best = {n, n};
        for(int i = 0; i < n-1; i++){
            if((a[i].first ^ a[i+1].first) < minimum){
                best = {a[i].second, a[i+1].second};
                minimum =(a[i].first ^ a[i+1].first);
            }
        }
        long long x = (1 << k) -1; 
        x -= (origin[best.first-1].first | origin[best.second-1].first);  
        cout << best.first << " " << best.second << " " << x << "\n";
    }
    return 0;
}