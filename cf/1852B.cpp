/*
1852B
AC
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        pair<int, int> a[n]; 
        int b[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i].first;
            a[i].second = i;  
        }
        sort(a, a+n); 
        bool ans = true; 
        int tot = n, mod= 0;
        int i = 0, j = n-1; 
        while(tot){
            if(a[j].first + mod == tot){
                b[a[j].second] = tot; 
                tot--; 
                j--; 
                mod--;
            }
            else if(a[i].first + mod == 0){
                b[a[i].second] = -tot; 
                tot--; 
                i++; 
            }
            else{
                ans = false; 
                break; 
            }
        }
        if(!ans){
            cout << "NO\n"; 
        }
        else{
            cout << "YES\n"; 
            for(int i = 0; i< n; i++){
                if(i) cout << " "; 
                cout << b[i];
            }
            cout << "\n";
        }
    }
    return 0;
}