/*
1003B
*/

#include <iostream>

using namespace std; 

int main(){
    int a, b, x; cin >> a >> b >> x; 
    int turn = (b > a);

    while(a + b > 0){ 

        if(b && turn){
            cout << 1; 
            --b; 
        }
        else if(a){ 
            cout << 0;
            --a; 
        }
        else{
            cout << 1; 
            --b; 
        }

        if(x > 1){
            --x; 
            turn = 1 - turn; 
        }
    }
    cout << "\n";
    return 0;
}