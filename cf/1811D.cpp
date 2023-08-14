/*
1811D
AC
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long f[46] = {1, 1};
    for(int i = 2; i < 46; i++){
        f[i] = f[i-1] + f[i-2];
    }
    int t; cin >> t; 
    while(t--){
        long long n, x, y; 
        bool ans = true; 
        cin >> n >> x >> y;
        while(n > 1){
            if(y > f[n]){
                y = y - f[n];
                swap(x, y);
            }
            else if(y <= f[n-1]){
                swap(x, y);
            }
            else{
                ans = false; 
                break; 
            }
            n--;
        }
        if(ans) cout << "yes\n"; 
        else cout << "no\n";
    }
    return 0;
}