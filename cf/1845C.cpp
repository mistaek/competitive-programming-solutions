/*
1845C
AC
*/

#include <iostream>
#include <string>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        string s; cin >> s; 
        int m; cin >> m;
        string l, r; cin >> l >> r; 
        int i = 0, j = 0, cur = l[0] - '0'; 
        int found = 0;
        for(; i < s.length(); i++){
            if(j >= m) break; 
            found |= (1 << (s[i] - '0')); 
            //cout << found << " ";

            int nxt = cur; 
            while((nxt <= (r[j] - '0')) && (found & (1 << nxt))){
                nxt++; 
            }
            if(nxt > (r[j] - '0')){
                //cout << cur;
                j++; 
                if(j >= m) break; 
                cur = l[j] -'0';
                found = 0;
            }
            else{
                cur = nxt;
            }
        }
        //cout << "\n";
        cout << ((j <m) ? "YES" : "NO") << "\n";
    }    
    return 0;
}