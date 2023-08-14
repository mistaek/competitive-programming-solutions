/*
1710A
AC, watch bounds...
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        long long n, m, k; cin >> n >> m >> k; 
        vector<long long> a(k);
        for(int i = 0; i < k; i++) cin >> a[i];
        bool a1 = false, a2 = false; 

        long long r = 0, c = 0; 
        long long o1 = 0, o2 = 0;
        for(int i = 0; i < k; i++){
            if(a[i]/n > 1){
                c+= a[i]/n; 
                if(a[i]/n > 2) o1 = 1; 
            }
            if(a[i]/m > 1){
                r+= a[i]/m; 
                if(a[i]/m > 2) o2=1;
            }
        }
        //cout << r << " " << o2 << "\n" << c << " " << o1 << "\n";
        if(r >= n && o2 >= n % 2){
            a1 = true; 
        }
        if(c >= m && o1 >= m % 2){
            a2 = true; 
        }
        if(a1 || a2) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}