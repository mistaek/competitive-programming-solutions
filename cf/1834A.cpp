/*
1834A
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        int neg = 0, sum = 0;
        for(int i = 0; i < n; i++){
            int a; cin >> a; 
            sum += a; 
            if(a < 0) neg++; 
        }
        int ans = 0; 
        if(sum < 0){
            ans = abs(sum -1)/2; 
        }
        if((neg - ans) % 2) ans++;
        cout << ans << "\n";
    }
}  