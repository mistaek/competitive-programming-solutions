/*
1861A
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std; 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        string n;
        cin >> n; 
        for(int i = 0; i < n.length(); i++){
            if(n[i] == '1' || n[i] == '3') cout << n[i]; 
        }
        cout << "\n";
    }

    return 0;
}