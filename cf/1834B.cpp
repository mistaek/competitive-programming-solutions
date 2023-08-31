/*
1834B
*/

#include <iostream>
#include <string>
using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        string l, r; 
        cin >> l >> r; 
        int ans = 0;
        if(r.length() > l.length()){
            ans = ((r.length()-1) * 9) + (r[0] - '0');
        }
        else{
            for(int i = 0; i < l.length(); i++){
                if(r[i] != l[i]){
                    ans += (l.length() - i -1) * 9;
                    ans += r[i] - l[i]; 
                    break; 
                }
            }
        }
        cout << ans << "\n";

    }
    return 0;
}