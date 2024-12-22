/*
1004C
*/

#include <iostream>
#include <set>

using namespace std; 

int main(){
    int n; cin >> n; 
    int a[n], psa1[n] = {};
    set<int> cnt; 

    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(cnt.find(a[i]) == cnt.end()){
            //this is first appearnce from left of a[i]
            psa1[i] = 1; 
            cnt.insert(a[i]);
        }
        if(i) psa1[i] += psa1[i-1];
    }
    cnt.clear();
    long long ans = 0;
    for(int i = n-1; i >= 0; --i){
        if(cnt.find(a[i]) == cnt.end()){
            //first appearance, choose any number whose first appearance is before i
            if(i) ans += psa1[i-1];
            cnt.insert(a[i]);
        }
    }
    cout << ans << "\n";

    return 0;
}