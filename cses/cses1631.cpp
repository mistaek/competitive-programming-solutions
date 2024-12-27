/*
cses1631
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main(){
    int n; cin >> n; 
    vector<long long> a(n); 
    long long total =0;
    for(int i = 0; i < n; ++i){cin >> a[i]; total += a[i];}
    sort(a.begin(), a.end()); 
    if(a[n-1] > total - a[n-1]) cout << a[n-1] * 2LL << "\n"; 
    else cout << total << "\n";
    return 0;
}