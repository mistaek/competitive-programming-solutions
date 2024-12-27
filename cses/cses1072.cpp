/*
CSES1072
*/

#include <iostream>

using namespace std; 

int main(){
    long long n; cin >> n;  
    
    for(long long i = 1; i <= n; ++i){
        //i^2 choose 2
        cout << ((i * i) *(i*i - 1))/2LL - 4*(i-1) * (i-2) << "\n";
    }
    return 0;
}