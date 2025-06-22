/*
1536C
AC
*/

#include <iostream>
#include <map>
#include <numeric>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int ans[n+1];
        map<pair<int, int>, int> prev; 
        ans[0] = 0; 
        int cnt = 0; //count Ds
        for(int i = 1; i <= n; ++i){
            char c; cin >> c; 
            if(c == 'D') ++cnt; 
            if(i > 1) cout << " "; 
            if(cnt == 0){
                cout << i; // special case
            }
            else{
                int gcdd = gcd(cnt, i); 
                //cout << "RATIO " << cnt/gcdd << " " << i /gcdd << "\n";
                ans[i] = 1 + ans[prev[{cnt/gcdd, i/gcdd}]]; 
                cout << ans[i]; 
                prev[{cnt/gcdd, i/gcdd}] = i;
            }
        }
        cout << "\n";
    }
    
    return 0;
}