/*
1155A
*/
    
#include <iostream>
#include <string>
    
using namespace std; 
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0); 
    
    int n; cin >> n; 
    string s; cin >> s; 
    
    int l = -1, r = -1; 
    char maxc = 'a';
    for(int i = 0; i < n; ++i){
        if(s[i] > maxc){
            maxc = s[i]; 
            l = i; 
        }
        if(s[i] < maxc){
            r = i; 
            break; 
        }
    }
    
    if(r != -1){
        cout << "YES\n"; 
        cout << l+1 << " " << r+1 << "\n"; 
    }
    else cout << "NO\n"; 
    return 0;
}