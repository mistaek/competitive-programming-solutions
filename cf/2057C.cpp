/*
2057C
*/

#include <iostream>

using namespace std; 

int ans[3], mod = 0; 
void solve(int l, int r){
    int msbr = 0, msbl = -1;
    for(int i = 0; i < 30; ++i){
        if(r & (1 << i)) msbr = i; 
    }
    for(int i = 0; i < 30; ++i){
        if(l & (1 << i)) msbl = i; 
    }
    if(msbl == msbr){
        mod += (1 << msbr); 
        solve(l - (1 << msbl), r - (1 << msbr)); 
    }
    else if(msbr - msbl >= 2){
        ans[0] = (1 << (msbr - 1)) - 1; 
        ans[1] = (1 << (msbr - 1)); 
        ans[2] = (1 << (msbr)); 
    }
    else{
        if((1 << msbr) - 2 >= l){
            ans[0] = (1 << msbr) -2;  
            ans[1] = (1 << msbr) - 1;
            ans[2] = (1 << msbr); 
        }
        else{
            ans[0] = (1 << msbr) - 1; 
            ans[1] = (1 << msbr); 
            ans[2] = (1 << msbr) + 1; 
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0); 
    
    int t; cin >> t; 
    while(t--){
        //int a, b, c; cin >> a >> b >> c; 
        //cout << (a^b) + (b ^c ) + (c ^ a) << "\n"; 
        mod = 0;
        int l, r; cin >> l >> r; 
        solve(l, r);
        cout << ans[0] + mod << " " << ans[1] + mod << " " << ans[2] + mod << "\n";
    }
    return 0;
}