/*
1154D
*/

#include <iostream>
#include <vector>
using namespace std; 

int main(){
    int n, b, a; cin >> n >> b >> a; 
    int cap = a; 
    int s; 
    for(int i = 0; i < n; ++i){
        cin >>s; 
        if(a == cap || (b  == 0 && a > 0) || (s == 0 && a > 0)){
            --a; 
            //cout << s << " A " << a << " " << b << "\n";

        }
        else if(b > 0){
            if(s) ++a;
            --b; 
            //cout << s << " B " << a << " " << b << "\n";

        }
        else{
            cout << i << "\n";
            return 0;
        }
    }

    cout << n << "\n"; 
    return 0;
}