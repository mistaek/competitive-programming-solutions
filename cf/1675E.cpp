/*
1675E
AC
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n, k; cin >> n >> k; 
        string str; 
        cin >> str; 
        vector<int> s(n);
        for(int i = 0; i < n; i++){
            s[i] = str[i] - 'a';
        }
        int max = 0, m2 =0, a2 = 0;
        for(int i = 0; i < n; i++){
            if(s[i] > max){
                if(k >= s[i] - max){
                    k -= s[i] - max;
                    max = s[i]; 
                }
                else{
                    m2 = s[i]; 
                    s[i] -= k;
                    a2 = s[i];
                    k = 0;
                    break; 
                }
            }
        }

        for(int i = 0; i < n; i++){
            char c;
            if(a2 <= s[i] && s[i] <= m2) c = 'a' + a2; 
            else if(s[i] <= max) c = 'a'; 
            else c = 'a' + s[i];
            cout << c; 
        }
        cout << "\n";
    }    


    return 0;
}