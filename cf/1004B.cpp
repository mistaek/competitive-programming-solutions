/*
1004B
*/

#include <iostream>
#include <set>

using namespace std; 

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i){
        int a; cin >> a; 
    }

    for(int i = 0; i < n; ++i){
        cout << i %2; 
    }
    cout << "\n";
    return 0;
}