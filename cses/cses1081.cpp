/*
1081
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n; cin >> n; 
    int cnt[1000001] = {};
    for(int i = 0; i < n; ++i){
        int x; cin >> x; 
        cnt[x]++;
    }

    int best = 1; 
    for(int i = 2; i <= 1000000; ++i){
        int found = 0;
        for(int j = i; j <= 1000000; j += i){
            found += cnt[j]; 
            if(found >= 2){
                best = i; break; 
            }
        }
        
    }
    cout << best << "\n";
    return 0; 
}