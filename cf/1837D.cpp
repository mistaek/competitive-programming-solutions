/*
1837D
AC
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        string s; cin >> s; 
        int colors[n]={};
        int c1f = 0, c2f = 0;
        int c1 =0 , c2 = 0, c1c = 0, c2c = 0;
        int cnt1 = 0, cnt2 = 0; 
        if(s[0] == '('){
            c1 = 1; c2 = 2; 
        }
        else{
            c1 = 2; c2 = 1; 
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '(') cnt1++; 
            else cnt2++; 

            if(s[i] == '('){
                if(c2c){
                    c2c--;
                    colors[i] = c2; 
                }
                else{
                    c1f = 1;
                    c1c++;
                    colors[i] = c1; 
                }

            }
            else{
                if(c1c){
                    c1c--;
                    colors[i] = c1; 
                }
                else{
                    c2f = 1;
                    c2c++; 
                    colors[i] = c2; 
                }
            }
        }
        if(cnt1 != cnt2){
            cout << -1 << "\n";
            continue; 
        }
        else{
            cout << c1f +c2f << "\n";
            for(int i =0;i < n; i++){
                if(i) cout << " "; 
                cout << colors[i];
            }
            cout << "\n";
        }


    }
    return 0;
}