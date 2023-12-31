/*
1912K
ac
*/

#include <iostream>

using namespace std; 

int mod = 998244353;

int main(){
    //cin.tie(0); 
    //ios_base::sync_with_stdio(false);
    int n; cin >> n; 
    long long cnt[3][8]= {};

    for(int i = 0; i < n; i++){
        int a; cin >> a; 
       
        a %= 2; 

        if(a == 0){
            cnt[2][6] += cnt[1][3] + cnt[2][3];
            cnt[2][0] += cnt[1][0] + cnt[2][0];
            cnt[1][2] += cnt[0][1];
            cnt[1][0] += cnt[0][0];
            cnt[0][0]++; 
        }
        if(a == 1){
            cnt[2][3] += cnt[1][1] + cnt[2][5];
            cnt[2][5] += cnt[1][2] + cnt[2][6];
            cnt[1][1] += cnt[0][0];
            cnt[1][3] += cnt[0][1]; 
            cnt[0][1]++; 
        }
        for(int j = 0; j < 3; j++){
            for(int k = 0;  k < 8; k++){
                //if(cnt[j][k] != 0) cout << j << " " << k << " " << cnt[j][k] << "\n";
                cnt[j][k] %= mod; 
            }
        }
    }
    long long ans = cnt[2][0] + cnt[2][3]; 
    ans %= mod; 
    ans += cnt[2][5];
    ans %= mod; 
    ans += cnt[2][6]; 
    ans %= mod;
    cout << ans << "\n";
    return 0;
}