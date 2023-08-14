/*
1804C
AC
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        long long n, x, p; 
        cin >> n >> x >> p;
        bool ans = false; 
        for(long long f = 1; f <= min(2*n, p); f++){
            long long res = ((f*(f+1))/2) + x;
            if(res % n == 0){
                ans = true; break; 
            }
        }
        if(ans){
            cout << "yes\n"; 
        }
        else cout << "no\n";
    }
    return 0;
}