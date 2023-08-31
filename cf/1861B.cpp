/*
1861B
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
        string a, b; 
        cin >> a >> b; 
        bool ans = true; 
        for(int i = 0; i < a.length(); i++){
            if(a[i] == '1' && b[i] == '1'){
                break; 
            }
            if(a[i] != b[i]){
                while(i < a.length() && (a[i] != b[i] || a[i] == '1')){
                    i++;
                }
                if(i == a.length()){
                    ans = false; 
                    break;
                }
            }
        }
        if(ans) cout << "YES\n"; 
        else cout << "NO\n";
    }
    
    return 0;
}