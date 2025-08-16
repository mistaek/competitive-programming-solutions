/*
1165B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n; 
    vector<int> a(n); 
    for(int i = 0; i < n; ++i) cin >> a[i]; 
    sort(a.begin(), a.end()); 
    int day = 0;
    for(int i = 0; i < n; ++i){
        while(i < n && a[i] <= day){
            ++i; 
        }
        if(i < n && a[i] > day) ++day; 
    }
    cout << day <<"\n";
    return 0;
}