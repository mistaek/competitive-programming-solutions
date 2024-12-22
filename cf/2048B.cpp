/*
2048A
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        vector<int> p(n, 0);
        int ctr = 1; 
        for(int i = k-1; i <n; i += k){
            p[i] = ctr++;
        }
        for(int i = 0; i < n; ++i){
            if(i) cout << " "; 
            if(p[i] == 0) p[i] = ctr++;
            cout << p[i]; 
        }
        cout << "\n";

    }
    return 0;
}