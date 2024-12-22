/*
1003A
*/

#include <iostream>
#include <algorithm>

using namespace std; 

int main(){
    int n; cin >> n; 
    int cnt[101] = {};
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        cnt[a]++;
    }
    int ans = 1;
    for(int i = 0; i <= 100; ++i){
        ans = max(ans, cnt[i]); 
    }

    cout << ans << "\n";
    return 0;
}