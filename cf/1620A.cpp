/*
1620A
AC
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); 

    int t; cin >> t; 
    while(t--){
        string info; cin>>info;
        vector<int> s(info.length());
        s[0] = 0; 


        for(int i = 0; i < info.length()-1; i++){
            if(info[i] == 'E') s[i+1] = s[i];
            else s[i+1] = s[i]+1; 
        }

        if(info[info.length() -1] == 'E' && s[info.length() -1] == 1) cout <<"NO\n";
        else if(info[info.length() -1] == 'N' && s[info.length() -1] == 0) cout << "NO\n"; 
        else cout << "YES\n";
         
    }
    return 0;
}