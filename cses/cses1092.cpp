/*
cses1092
*/

#include <iostream>

using namespace std; 

int main(){
    int n; cin >> n; 
    if(n %4 == 0){
        cout << "YES\n";
        cout << n/2 << "\n";
        for(int i = 0; i < n/4; ++i){
            if(i) cout << " "; 
            cout << (i*4) + 1 << " " << (i*4) + 4; 
        }
        cout << "\n";
        cout << n/2 << "\n";
        for(int i = 0; i < n/4; ++i){
            if(i) cout << " "; 

            cout << (i*4) + 2 << " " << (i*4) + 3;
        }
        cout << "\n"; 
    }
    else if(n%4 == 3){
        cout << "YES\n";
        cout << 2 + (n - 3)/2 << "\n"; 
        cout << 1 << " " << 2; 
        n -= 3; 
         for(int i = 0; i < n/4; ++i){
            cout << " "; 

            cout << (i*4) + 4 << " " << (i*4) + 7; 
        }
        cout << "\n"; 
        cout << 1 + n/2 << "\n3"; 

        for(int i = 0; i < n/4; ++i){
            cout << " "; 
            cout << (i*4) + 5 << " " << (i*4) + 6;
        }
        cout << "\n";
    }
    else cout << "NO\n";
    return 0;
}