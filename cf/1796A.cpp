/*
1796A
*/

#include <iostream>
#include <string>

using namespace std; 
//FBFFBFFB
int main(){
    int t; 
    cin>>t; 
    string fb = "FBFFBFFB";
    while(t--){
        int length; cin >> length; 
        string in; 
        cin >> in;  
        bool ans = true; 
        for(int i = 0; i < 8; i++){
            ans = true; 
            for(int j = 0; j < length; j++){
                if(fb[(j+i) % 8] != in[j]) ans = false; 
            }
            if(ans){
                break; 
            }
        }
        if(ans) cout <<"yes\n"; 
        else cout << "no\n";
    }
    return 0;
}