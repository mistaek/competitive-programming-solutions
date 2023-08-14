/*
ecoo2021p5
wip
*/

#include <cstdio>
#include <set>
#include <iostream>
using namespace std; 
//lets grab partials for now
int main(){
    int x = 0, y = 0, ans = 0; 
    for(int i = -10; i <= 10; i++){
        for(int j = -10; j <= 10; j++){
            cout << "? " << i << " " << j << endl;
            int a, b; cin >> a >> b; 
            if(a == i && b == j) ans++;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}