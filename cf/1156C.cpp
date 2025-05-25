/*
1156C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 


    int n, z; 
    cin >> n >> z; 
    vector<int> a(n); 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }

    sort(a.begin(), a.end()); 
    int lo = 0, hi = n/2; 
    while(lo < hi){
        int mid = (lo+hi+1)/2; 
        bool pos = true; 
        for(int i = 0; i < mid; ++i){
            if(a[n - mid +i] - a[i] < z){
                pos = false; break; 
            }
        }
        if(pos) lo = mid; 
        else hi = mid-1; 
    }
    cout << lo << "\n";
    return 0;
}