/*
1841B
*/

#include <vector>
#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t; cin >> t; 
    while(t--){
        int q; cin >> q; 
        int min = -1, last = -1;
        bool inv = false;  
        while(q--){
            int x; cin >> x; 
            if(min == -1) min = x; 
            if(inv){
                if(x > min){
                    cout << 0; 
                }
                else if(x < last){
                    cout << 0; 
                }
                else{
                    cout << 1; 
                    last = x; 
                }
            }
            else{
                if(x < min){
                    inv = true; 
                    cout << 1; 
                    last = x; 
                }
                else if(x < last){
                    if(x <= min){
                        inv = true; 
                        cout << 1; 
                        last = x; 
                    }
                    else{
                        cout << 0; 
                    }
                }
                else{
                    cout << 1; 
                    last = x; 
                }
            }
            
        }
        cout << "\n";
    }
    return 0;
}