/*
1042D
ac
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

vector<long long> a; 
long long n, t; 
long long solve(int l, int r){
    if(l == r){
        return (a[l] < t) ? 1 : 0;
    }

    int m = (l+r)/2; 
    long long ans = solve(l, m) + solve(m+1, r);
    vector<long long> leftsums, rightsums; 
    long long s = 0;
    for(int i = m; i >= l; --i){
        s += a[i]; 
        leftsums.push_back(s);
    }
    s = 0; 
    for(int i = m+1; i <= r; ++i){
        s += a[i]; 
        rightsums.push_back(s);
    }
    sort(leftsums.begin(), leftsums.end()); 
    sort(rightsums.begin(), rightsums.end()); 

    //kinda slow but idc
    for(long long ls : leftsums){
        auto it = lower_bound(rightsums.begin(),rightsums.end(), t - ls);
        ans += (it - rightsums.begin()); 
    }
    return ans; 

}
int main(){
    cin >> n >> t; 
    a = vector<long long>(n); 
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
    }

    cout << solve(0, n-1) << "\n"; 


    return 0;
}