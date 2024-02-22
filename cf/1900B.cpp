/*
1900B
*/

#include <iostream>

using namespace std; 

int test(int a, int b, int c){
    if(b < c) swap(b, c);
    a += c; 
    b -= c; 
    c -= c; 
    if(b % 2) return 0; 
    if(a == 0) return 0;
    return 1; 
}
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int a, b, c; cin >> a >> b >> c; 
        int a1 = 0, a2 = 0, a3 = 0;
        //test 1
        a1 = test(a, b, c); 
        a2 = test(b, a, c); 
        a3 = test(c, a, b);

        cout << a1 << " " << a2 << " " << a3 << "\n";
    }
    return 0;
}