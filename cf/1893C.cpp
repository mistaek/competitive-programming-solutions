/*
1893C
AC, wahsy
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    int t; cin >> t; 
    while(t--){
        int m; cin >> m; 
        int tn = 0;
        vector<vector<long long>> ms(m), msn(m); 
        vector<long long> sn(m, 0), l(m), r(m);
        //up to 4 * 10e5 numbers
        long long sl = 0, sr = 0; 
        for(int i = 0; i < m; i++){
            int n;
            cin >> n >> l[i] >> r[i]; 
            sl += l[i], sr += r[i]; 
            for(int j = 0; j < n; j++){
                long long v; cin >> v; 
                ms[i].push_back(v); 
            }
            for(int j = 0; j < n; j++){
                long long v; cin >> v; 
                msn[i].push_back(v); 
                sn[i] += v;
            }
            tn += n;
        }

        if(sr - sl +1 > tn){
            cout << 0 << "\n";
            continue;
        }

        vector<long long> score(sr - sl + 1, 0); //minimal score
        vector<long long> lsm(sr- sl + 1, sr); //largest possible set with minimum num of i
        //O(N) = 1e5
        for(int i = 0; i < m; i++){
            for(int j = 0; j < ms[i].size(); j++){
                if(ms[i][j] <= sr && ms[i][j] >= sl){
                    if(l[i] + msn[i][j] - sn[i] > 0){
                        score[ms[i][j] - sl] += l[i] + msn[i][j] - sn[i]; // must pick
                    }
                    lsm[ms[i][j] - sl] -= r[i]; 
                    lsm[ms[i][j] - sl] += max(l[i], min(sn[i] - msn[i][j], r[i]));
                }
            }
        }
        long long ans = 1e17; 
        for(long long i = 0; i < sr - sl + 1; i++){
            long long isc = score[i] + max(0LL, sl + i - lsm[i]);
            //cout << isc << " "; 

            ans = min(ans, max(0LL, isc));
        }
        //cout << "\n";
        cout << ans << "\n";

        
    }
    return 0;
}