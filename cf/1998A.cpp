/*
1998A
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);    

    int tc; cin >> tc; 
    while(tc--){
        int x, y, k; cin >> x >> y >> k; 

        int cur = 1;
        if(k % 2){
            cout << x << " " << y << "\n";
            --k;
        }

        while(k){
            cout << x + cur << " " << y << "\n";
            cout << x - cur << " " << y << "\n";
            k -=2; 
            ++cur; 
        }
    }

    return 0;
}