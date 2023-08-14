/*
1796B
*/

#include <iostream>
#include <string>

using namespace std; 
//FBFFBFFB
int main(){
    
    int t; cin >> t; 
    while(t--){
        string a, b; cin >> a >> b;
        if(a[0] == b[0]){
            cout << "YES\n";
            cout << a[0] << "*\n";
        }
        else if(a[a.length() - 1] == b[b.length() - 1]){
            cout << "YES\n"; 
            cout << "*" << a[a.length() - 1]  <<"\n"; 
        }
        else if(a.length() >= 2 && b.length() >= 2){
            for(int i = 0; i < a.length() - 1; i++){
                bool ans = false; 
                for(int j = 0; j < b.length() - 1; j++){
                    if(b[j] == a[i] && b[j+1] == a[i+1]){
                        cout << "YES\n";
                        cout << '*' << a[i] << a[i+1] << "*\n";
                        ans = true; 
                        break; 
                    }
                }
                if(ans) break; 
                if(i == a.length() - 2) cout << "NO\n";
            }
            
        } 
        else cout << "NO\n";
        
    }
    return 0;
}