/*
FHC2022R1B1
*/

#include <iostream>
#include <vector>

using namespace std; 

long long mod = 1e9+7;
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    for(int tc = 1; tc <= t; tc++){
        int n, q; cin >> n;
        vector<pair<long long, long long>> xy(n); 
        long long xs = 0 ,ys =0, xsqr = 0, ysqr = 0;
        for(int i = 0; i < n; i++){
            long long a, b; cin >> a >> b; 
            xy[i] = make_pair(a, b); 
            xs += a; xs %= mod; 
            ys += b; ys %= mod; 
            long long s1 = a * a, s2 = b * b; 
            s1 %= mod; s2 %= mod; 
            xsqr += s1; ysqr += s2; 
            xsqr %= mod; ysqr %= mod;
        }
        long long ans = 0;
        cin >> q; 
        for(int i = 0; i < q; i++){
            long long a, b; cin >> a >> b; 
            long long nx = a * a, ny = b * b; 
            nx %= mod; ny %= mod; 
            nx *= n; ny *= n; 
            nx %= mod; ny %= mod;
            ans += nx; ans %= mod; 
            ans += ny; ans %= mod;
            ans += xsqr; ans %= mod; 
            ans += ysqr; ans %= mod;

            long long prodx = 2*a, prody = 2*b; 
            prodx %= mod; prody %= mod; 
            prodx *= xs; prodx %= mod; 
            prody *= ys; prody %= mod; 
            ans -= prodx; 
            ans %= mod; 
            if(ans < 0) ans += mod; 
            ans -= prody; 
            ans %= mod; 
            if(ans < 0) ans += mod; 
            ans %= mod;
        }
        ans %= mod; 
        cout << "Case #" << tc << ": " << ans << "\n";


        
    }
    return 0;
}