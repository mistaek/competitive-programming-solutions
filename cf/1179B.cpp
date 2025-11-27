/*
1179B
*/

#include <iostream>

using namespace std; 

int main(){
    int n, m; cin >> n >> m;

    int tr = 1, br = n, tc = 1, bc = m;
    int t = 0, ctr = 0; 
    while(ctr != n*m){
        ++ctr; 
        if(t == 0){
            cout << tr << " " << tc << "\n"; 
            ++tc; 
        }
        else {
            // reset should always happen here
            cout << br << " " << bc << "\n"; 
            if(--bc == 0){
                //reset
                ++tr; --br; 
                tc = 1, bc = m; 
            }
        }

        t = 1-t; 
    }    
    return 0;
}