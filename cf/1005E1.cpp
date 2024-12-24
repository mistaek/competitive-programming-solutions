/*
1005 E1
AC
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std; 

int main(){
    int n, m; cin >> n >> m; 
    int mpos; 
    map<int, long long> cnt[2]; //could use an indexed array but im lazy
    int a[n]; 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        if(a[i] == m) mpos = i;
    }
    int gm = 0, lm = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] > m) ++gm; 
        else if(a[i] < m) ++lm;

        if(i >= mpos){
            cnt[i % 2][gm -lm]++;
        }
    }
    
    gm = 0, lm = 0;
    long long ans = 0;
    for(int i = 0; i <= mpos; ++i){
        // want gm - lm
        ans += cnt[i%2][gm - lm]; // ODD, DELTA IS 0
        ans += cnt[(i+1)%2][gm - lm +1]; //EVEN, DELTA IS 1
        if(a[i] > m) ++gm; 
        if(a[i] < m) ++lm;
    }

    cout << ans << "\n";
    return 0;
}