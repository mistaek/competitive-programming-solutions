/*
1907F
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

vector<int> a; 
int cl = -1, cr = -1; 

void chk(int i, int d){
    int n = a.size(); 
    //cout << i << " " << d << "\n"; 
    for(int j = 0; j < n-1; j++){
        if(a[(i + j*d + n) % n]  > a[(i + (j+1)*d + n) % n]){
            //cout << (i + j * d + n ) % n << "\n"; 
            if(d < 0) cl = -2;
            else cr = -2; 
            return; 
        }
    }
    if(d < 0) cl = i; 
    else cr = i; 
}

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        a = vector<int>(n); 
        int mn = 1e9, mx = 0;
        cl = cr = -1;
        for(int i = 0; i < n; i++){ 
            cin >> a[i];
            mn = min(mn, a[i]); mx = max(mx, a[i]);
        }
        if(mn == mx){
            cout << 0 << "\n";
            continue;
        }
        for(int i = 0; i < n; i++){
            if(cl == -1 && a[i] == mn && a[(i+1) % n] == mx){
                chk(i, -1);
            }
            if(cr == -1 && a[i] == mx && a[(i+1) % n] == mn){
                chk((i+1) % n, 1);
            }
        }
        int ans = 1e9 + 100;
        if(cl >= 0){
            int dist = min(n - 1 - cl, (cl + 1) % n);
            ans = min(ans, dist+1);


        }
        if(cr >= 0){
            int dist = min(2 + cr, n - cr);
            if(cr == 0) dist = 0;
            ans = min(ans, dist); 
        }
        //cout << cl << " " << cr << "\n";
        if(cl < 0 && cr < 0) cout << -1 << "\n"; 
        else cout << ans << "\n";        
    }
    return 0;
}