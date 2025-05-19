/*
2109B
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
#include <map> 
#include <functional>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        int a, b; cin >> a >> b; 
        int turn = 1, ans = 1e9;
        //cut by x first 
        int y = n, x = m - max(b-1, m-b); 
        int aa = a, bb = b; 
        while(y > 1 || x > 1){
            aa = (y+1)/2; bb = (x+1)/2; 
            int yd = max(y - aa, aa-1); 
            int xd = max(x -bb, bb-1); 
            if(yd > xd) y = y - yd; 
            else x = x - xd; 
            ++turn;
        }

        ans = min(ans, turn);
        turn = 1; 
        aa = a, bb = b; 
        y = n - max(n-a, a-1), x = m; 
        while(y > 1 || x > 1){
            aa = (y+1)/2; bb = (x+1)/2; 
            int yd = max(y - aa, aa-1); 
            int xd = max(x -bb, bb-1); 
            if(yd > xd) y = y - yd; 
            else x = x - xd; 
            ++turn;
        }

        ans = min(ans, turn); 
        cout << ans << "\n";
    }
    return 0;
}