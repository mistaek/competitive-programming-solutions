/*
1161A
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n, k; cin >> n >> k; 
    long long ans = 0;
    vector<int> prefix(n+1, 0), suffix(n+1, 0); 

    vector<int> a(k); 
    for(int i = 0; i < k; ++i){
        cin >> a[i];
        suffix[a[i]]++; 
    }

    for(int i = 0; i < k; ++i){
        if(prefix[a[i]] == 0 && suffix[a[i]]){
            
            if(a[i] + 1 <= n && suffix[a[i] + 1] == 0) ++ans; 
            if(a[i] - 1 >= 1 && suffix[a[i] - 1] == 0) ++ans; 
        }
        --suffix[a[i]];
        ++prefix[a[i]];
    }
    for(int i = 1; i <= n; ++i){
        if(prefix[i] == 0){
            if(i == 1 || i == n) ans += 2; 
            else ans +=3; 
        }
    }

    cout << ans << "\n";

    return 0;
}