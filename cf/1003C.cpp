/*
1003C
*/

#include <iostream>
#include <iomanip>

using namespace std; 

int main(){
    int n, k; cin >> n >> k;

    int a[n]; for(int i = 0; i < n; ++i) cin >> a[i];
    double ans = 0;
    for(int i = 0; i < n; ++i){
        int s = 0;
        for(int j = 0; j < n; ++j){
            if(i + j >= n ) break; 
            s += a[i+j];
            //cout << i << " " << i+j << " " << (double)s/(j+1) << "\n";
            if(j+1 >= k) ans = max(ans, (double)s/(j +1));

        }
    }
    cout << fixed << setprecision(9);
    cout <<ans << "\n";
    return 0;
}