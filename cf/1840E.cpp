/*
1840E
AC
*/

#include <iostream>
#include <string>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int T; cin >> T; 
    while(T--){
        string s[2]; cin >> s[0] >> s[1]; 
        int t, q; cin >> t >> q; 
        int diff =0; 
        for(int i = 0; i < s[0].length(); i++){
            if(s[0][i] != s[1][i]) diff++;
        }
        int blocked[t+q+1] ={};
        for(int i = 1; i <= q; i++){
            int type; cin >> type; 
            if(blocked[i] != 0){
                if(s[0][blocked[i]-1] != s[1][blocked[i]-1]) diff++;
            }
            if(type == 1){
                int pos; cin >> pos; 
                blocked[i + t] = pos; 
                if(s[0][pos-1] != s[1][pos-1]) diff--;
            }
            else if(type == 2){
                int id1, id2, pos1, pos2; cin >> id1 >> pos1 >> id2 >> pos2; 
                if(s[0][pos1-1] != s[1][pos1-1]) diff--; 
                if(s[0][pos2-1] != s[1][pos2-1]) diff--; 
                swap(s[id1-1][pos1-1], s[id2-1][pos2-1]);
                if(s[0][pos1-1] != s[1][pos1-1]) diff++; 
                if(s[0][pos2-1]!= s[1][pos2-1]) diff++; 
            }
            else{
                if(diff) cout << "no\n"; 
                else cout << "yes\n";
            }
            
            //cout << "\n";
        }
    }
    return 0; 
}
