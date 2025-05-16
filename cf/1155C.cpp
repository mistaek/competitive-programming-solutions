/*
1155C
*/
    
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
    
using namespace std; 
    
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;  
    
    long long gcd_ = -1, prev = -1, first = -1; 
    
    for(int i = 0; i < n; ++i){
        long long x; cin >> x; 
        if(first == -1) first = x; 
        if(i == 1) gcd_ = x-prev; 
        else gcd_ = gcd(gcd_, x - prev); 
    
        prev = x; 
    }
    
    int j = -1; 
    for(int i = 0; i < m; ++i){
        long long y; cin >> y; 
        if(gcd_ % y == 0) j = i+1; 
    }
    
    if(j > 0) cout << "YES\n" << first << " " << j << "\n"; 
    else cout << "NO\n"; 
    
    
    return 0;
}