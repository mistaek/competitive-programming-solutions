/*
2102B
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    cin.tie(0); cout.tie(0); 
    ios_base::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        vector<int> a(n); 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
            a[i] = abs(a[i]); 
        }
        int med = a[0];
        sort(a.begin(), a.end()); 
        int numbigger = 0;
        for(int i = n-1; i >= 0; i--){
            if(a[i] == med){
                break; 
            }
            numbigger++; 
        }
        // we know nums are distinct
        int ind = (n+1)/2; //ceil
        int need = min(n - ind, ind -1);
        //cout << numbigger << " " << ind << "\n";
        if(numbigger >= need) cout << "YES\n"; 
        else cout << "NO\n";
    }
    return 0;
}
