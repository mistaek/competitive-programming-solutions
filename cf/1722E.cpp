/*
1722E
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t; cin >> t; 
    while(t--){
        int n, q; cin >> n >> q; 
        vector<vector<long long>> a(1001, vector<long long>(1001, 0)), psa(1001, vector<long long>(1001, 0));
        int mw = 0, mh= 0;
        for(int i = 0; i < n; i++){
            int h, w; cin >> h >> w; 
            mw = max(mw, w); mh = max(mh, h);
            a[h][w] +=  h*w;
        }
        for(int i = 0; i <= mh; i++){
            for(int j = 0; j <= mw; j++){
                psa[i][j] = a[i][j]; 
                if(i) psa[i][j] += psa[i-1][j];
                if(j) psa[i][j] += psa[i][j-1];
                if(i && j) psa[i][j] -= psa[i-1][j-1];
            }
        }

        for(int i = 0; i < q; i++){
            int hs, ws, hb, wb; cin >> hs >> ws >> hb >> wb; 
            hb = min(mh+1, hb); wb = min(mw+1, wb);
            if(hs < mh && ws < mw){
                cout << psa[hb-1][wb-1] - psa[hb-1][ws] - psa[hs][wb-1] + psa[hs][ws] << "\n";
            }
            else cout << "0\n";
        }


    }
    return 0;
}