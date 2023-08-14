/*
1795A
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        int d = 0;
        bool ans = true; 
        char f1[n], f2[m]; 
        for(int i = 0; i < n; i++){
            cin >> f1[i]; 
            if(i && f1[i] == f1[i-1]){
                d++;
            }
        }
        for(int i = 0; i < m; i++){
            cin >> f2[i]; 
            if(i && f2[i] == f2[i-1]){
                d++;
            }
        }
        if(!ans || (d > 1) || ((d == 1) && (f1[n-1] == f2[m-1]))) cout << "no\n"; 
        else cout << "yes\n";
    }
    return 0;
}