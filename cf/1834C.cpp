/*
1834C
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        char a[n], b[n]; 
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
        }
        int fw = 0, rv = 0;
        for(int i = 0; i < n; i++){
            cin >> b[i]; 
            if(a[i] != b[i]) fw++;
        }
        if(fw % 2){
            fw = 2 * fw -1; 
        }
        else{
            fw = 2 * fw; 
        }

        for(int i = 0 ; i < n; i++){
            if(a[i] != b[n-i-1]) rv++;
        }
        if(rv % 2){
            rv = 2 * rv; 
        }
        else{
            rv = (2 * rv) - 1;  
        }
        cout << min(max(0, fw), max(2, rv)) << "\n"; 
        

        
    }
    return 0;
}