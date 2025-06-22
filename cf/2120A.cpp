/*
2120A
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int w[4], l[4]; 
        for(int i = 1; i <= 3; ++i) cin >> w[i] >> l[i]; 
        if(l[2] + l[3] == l[1] && w[2] == w[3] && w[1] + w[2] == l[1]){
            cout << "YES\n"; 
             
        }
        else if(w[2] + w[3] == w[1] && l[2] == l[3] && l[2] + l[1] == w[1]){
            cout << "YES\n"; 
        }
        else if(w[1] == w[2] && w[3] == w[1] && l[2] + l[3] + l[1] == w[1]){
            cout << "YES\n"; 
        }
        else if(l[1] == l[2] && l[3] == l[1] && w[1] + w[2] + w[3] == l[1]){
            cout << "YES\n"; 
        }
        else cout << "NO\n";
    }
    return 0;
}