/*
2128A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int t; cin >> t; 
    while(t--){
        int n, c; 
        cin >> n >> c; 
        vector<long long> trash(n, 0); 
        for(int i = 0; i < n; ++i) cin >> trash[i]; 
        sort(trash.begin(), trash.end()); 

        int turn = 0;
        int i = n-1; 
        while(i>= 0){
            trash[i] *= (1LL << turn); 
            if(trash[i] <= c){
                ++turn; 
            }
            --i; 
        }

        cout << n-turn << "\n"; 
    }
    return 0;
}