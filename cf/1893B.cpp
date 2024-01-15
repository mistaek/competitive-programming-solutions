/*
1893B
AC
*/

#include <iostream>
#include <algorithm>
#include <functional>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        int a[n], b[m];
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        for(int i = 0; i < m; i++){
            cin >> b[i]; 
        }

        sort(b, b+m, greater<int>());

        int pmax[n]={};
        for(int i = n-1; i >= 0; i--){
            pmax[i] = a[i];
            if(i < n-1) pmax[i] = max(pmax[i], pmax[i+1]); 
        }

        int i = 0, j = 0; 
        while(i < n || j < m){
            if(i + j) cout << " "; 
            if(i == n || (j < m && b[j] >= pmax[i])){
                cout << b[j];
                j++; 
            }
            else{
                cout << a[i]; 
                i++;
            }
        }
        cout << "\n";
    }
    return 0;
}