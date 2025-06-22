/*
1349A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n; cin >> n; 
    vector<long long> a(n); 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }

    sort(a.begin(), a.end());
    long long ans = a[n-1], prevGCD = a[n-1], curGCD = a[n-1];
    for(int i = n-2; i >= 0; --i){
        curGCD = gcd(curGCD, a[i]);
        if(i == n-2) ans = a[i] * prevGCD/curGCD; 
        else ans = gcd(ans, a[i] * prevGCD / curGCD); 
        prevGCD = gcd(prevGCD, a[i]);
    }
    cout << ans << "\n";
    return 0;
}