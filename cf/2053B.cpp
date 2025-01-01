/*
2053B
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        pair<int, int> lr[n];
        int preset[2*n+1] = {}, psa[2*n+1] = {};
        for(int i = 0; i < n; ++i){
            cin >> lr[i].first >> lr[i].second; 
            if(lr[i].first == lr[i].second) preset[lr[i].first]++;
        }

        for(int i = 0; i < 2*n+1; ++i){
            if(preset[i]) ++psa[i]; 
            if(i) psa[i] += psa[i-1];
            //cout << psa[i] << " "; 
        }
        //cout << "\n";

        for(int i = 0; i < n; ++i){
            if(lr[i].first == lr[i].second){
                cout << ((preset[lr[i].first] == 1) ? 1 : 0); 
            }
            else{
                cout << ((psa[lr[i].second] - psa[lr[i].first - 1] == lr[i].second - lr[i].first + 1) ? 0 : 1);
            }
        }
        cout << "\n";


    }
    return 0; 
}