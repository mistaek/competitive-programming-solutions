/*
1166C
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 

    int n; cin >> n; 
    vector<int> pos, neg, zeros; 
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        if(a > 0) pos.push_back(a); 
        else if(a < 0) neg.push_back(-a); 
    }
    long long ans = 0, pp = 0; 
    auto check = [&ans, &pp](vector<int>&v, vector<int>&sec){
        int j = 0, i2 = 0, j2=0; 
        
        for(int i = 0; i < v.size(); ++i){
            while(i2 < sec.size() && v[i] > sec[i2]) ++i2; 
            if(i2 < sec.size() && v[i] == sec[i2]) ++pp; 
            while(j2 < sec.size() && v[i] * 2 >= sec[j2]) ++j2; 
            while(j < v.size() && v[i] * 2 >= v[j]) ++j; 

            //all nums from i + 1 to j are options
            //cout << i << " " << j << " " << i2 << " " << j2 << "\n";
            ans += j-i-1 + j2-i2; 
        }
    };
    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());
    check(pos,neg); 
    check(neg, pos); 
    cout << ans - pp/2 << "\n"; 

    
    return 0; 
}