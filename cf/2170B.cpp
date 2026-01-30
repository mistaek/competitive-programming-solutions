/*
2170B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        long long total = 0, nonzero = 0;
        for(int i = 0; i < n; ++i){
            int bi; cin >> bi;
            total += bi;  
            if(bi) ++nonzero; 
        }

        cout << min(nonzero, total - n + 1) << "\n"; 
    }
    return 0;
}