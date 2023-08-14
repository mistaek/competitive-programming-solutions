/*
1838A
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int i1, i2, in; 
        for(int i = 0; i < n; i++){
            int a; cin >> a; 
            if(a == 1) i1 = i+1; 
            if(a == 2) i2 = i+1; 
            if(a == n) in = i+1; 
        }
        if(((i1 < in) && ( in< i2)) || ((i2 < in) && (in < i1))) cout << "1 1\n"; 
        else{
            if( ((i1 < i2) && (i2 < in)) || ((in < i2) && (i2 < i1))) cout << in << " " << i2 << "\n";
            else cout << in << " " << i1 << "\n";
        }
    }
    return 0;
}