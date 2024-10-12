/*
1998A
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

long long n, k; 
vector<pair<long long, long long>> a; 
vector<long long> b; 

bool test(long long v, vector<pair<long long, long long>> vec){
    long long kk = k; 
    for(int i = n-2; i >= 0; --i){
        if(kk && vec[i].first < v && b[vec[i].second] == 1){
            long long diff = min(kk, v - vec[i].first);
            kk -= diff;
            vec[i].first += diff;
        }
    }
    sort(vec.begin(), vec.end());
 
    if((n-1)%2) return vec[(n-1)/2].first >= v;
    return vec[((n-1)/2) - 1].first >= v; 
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int tc; cin >> tc; 
    while(tc--){
       cin >> n >> k;

        a = vector<pair<long long, long long>>(n); 
        b = vector<long long>(n);
        for(int i = 0; i < n; ++i){
            cin >> a[i].first;
            a[i].second = i;
        }
        for(int i = 0; i< n; ++i){
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        long long ans = 0;
        for(int i = n-1; i >= 0; --i){
            if(b[a[i].second] == 1){
                vector<long long> dup; 
                // take median of remaining numbers
                for(int j = 0; j < n; ++j){
                    if(j == i) continue; 
                    dup.push_back(a[j].first);
                }
                long long median; 
                if((n-1)%2) median = dup[dup.size()/2]; 
                else median = dup[(dup.size()/2) - 1];
                ans = a[i].first + k + median;
                break;
            }
        }

        //cout << ans << "\n";

        if(b[a[n-1].second] == 0){
            vector<pair<long long, long long>> dup; 
            for(int i = 0; i < n-1; ++i){ dup.push_back(a[i]);}
            //compute max possible
            long long lo = 1, hi = 3e9;
            while(lo < hi){
                long long mid = (lo + hi+1)/2; 
                if(test(mid, dup)){
                    lo = mid; 
                }
                else hi = mid-1; 
            }
            ans = max(ans, a[n-1].first + lo);
        }
        cout << ans << "\n";
    }
    return 0;
}