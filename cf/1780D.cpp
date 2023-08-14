/*
1780D
AC
*/

#include <iostream>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int ans = 0, k = 0, cnt, nxt = 0; 
        cin >> cnt; 
        while(cnt){
            int old = cnt; 
            if(nxt){
                cout << "- " << nxt << endl;
                nxt = 0; 
                cin >> cnt; 

            }
            else{ 
                cout << "- " << (1 << k) << endl;
                cin >> cnt; 
                for(int i = 0; i < cnt - old + 1; i++){
                    nxt += (1 << k); 
                    k++;
                }
                ans += (1 << k);
                k++;
            }
        }
        cout << "! " << ans << endl; 

    }
    return 0;
}