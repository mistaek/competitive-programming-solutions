/*
1163A
*/

#include <iostream>

using namespace std; 

int main(){
    int n, m; cin >> n >> m; 

    if(m == 0) cout << "1\n"; 
    else if(m <= n/2){
        cout << m << "\n";
    }
    else{
        int ans = n/2; 
        m -= n/2; 
        if(n % 2) --m; 
        cout << ans - m << "\n";
    }
    return 0;
}