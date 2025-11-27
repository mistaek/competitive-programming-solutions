/*
1175C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        vector<int> a(n); 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }
        int ptr = k;
        int best = 1e9, pt = 1; 
        for(; ptr < n; ++ptr){
            int avg = (a[ptr - k] + a[ptr])/2; 
            if(a[ptr] - avg < best){
                best = a[ptr] - avg; 
                pt = avg; 
            } 
        }   
        cout << pt << "\n";
    }
    return 0;
}