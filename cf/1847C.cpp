/*
1847C
AC
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    int t; cin>> t; 
    while(t--){
        int n; cin >>n; 
        int ans = 0; 
        int a[n] = {}, pos[256] = {}, npos[256] = {};
        pos[0] = 1; 
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            for(int j = 0; j < 256; j++){
                int xv = j^a[i];
                if(pos[j]){
                    ans = max(ans, xv);
                    npos[xv] = 1; 
                }
            }
            npos[0] = 1; 
            for(int j = 0; j < 256; j++){
                pos[j] = npos[j]; 
                npos[j] = 0;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}