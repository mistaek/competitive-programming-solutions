/*
1883E
AC
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; long long a[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        long long prev = 0, ans = 0;
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                for(int j = 1; j < 40; j++){
                    if((1 << j) * a[i] >= a[i-1]){
                        prev += j; 
                        break; 
                    }
                }
            }
            else if(a[i] > a[i-1]){
                for(int j = 1; j < 40; j++){
                    if((1 << j) * a[i-1] > a[i]){
                        prev -= j-1; 
                        break; 
                    }
                }
            }
            prev = max(0LL, prev);
            ans += prev;
            //cout << prev << " ";
        }
        cout << ans << "\n";
    }
    return 0;
}