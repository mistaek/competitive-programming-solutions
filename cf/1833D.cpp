/*
1833D
*/

#include <iostream>
#include <vector>
using namespace std; 

int main(){

    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        vector<int> p(n), b(n), a(n); 
        int r = 0; 
        for(int i = 0; i < n; i++){
            cin >> p[i];
            if(p[i] == n) r=i;
            if(p[0] == n && p[i] == n-1) r = i; //in case cannot take n
        }
        int idx = 0;
        for(int i = r; i < n; i++){
            b[idx++] = p[i]; 
        }
        for(int i = r-1; i >= 0; i--){
            b[idx++] = p[i];
        }
        
        for(int j= 1; j < r; j++){
            int idx = 0;
            for(int i = r; i < n; i++){
                a[idx++] = p[i]; 
            }
            for(int i = r-1; i >= j; i--){
                a[idx++] = p[i];
            }
            for(int i = 0; i < j; i++){
                a[idx++] = p[i]; 
            }
            bool betta = false; 
            for(int i = 0; i < n; i++){
                
                if(a[i] > b[i]){
                    betta = true; 
                }
                if(betta) b[i] = a[i];
                if(!betta && a[i] < b[i]) break; 
            }
        }
        if(r == n-1){
            a[0] = p[r];
            for(int i = 0; i < n-1; i++){
                a[i+1] = p[i];
            }
            bool betta = false; 
            for(int i = 0; i < n; i++){
                
                if(a[i] > b[i]){
                    betta = true; 
                }
                if(betta) b[i] = a[i];
                if(!betta && a[i] < b[i]) break; 
            }
        }
        for(int i = 0; i < n; i++){
            if(i) cout << " "; 
            cout << b[i];
        }
        cout << "\n";
    }
    return 0;
}