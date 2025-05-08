/*
1152C
*/

#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std; 
int main(){
    
    cin.tie(0);
    cout.tie(0); 
    ios_base::sync_with_stdio(0); 

    long long a, b; cin >> a >> b; 
    long long d = abs(b-a); 
    if(d <2){
        cout << 0 << "\n";
         return 0;
    }

    long long best = a* b / gcd(a,b), ans = 0; 
    for(int i = 1; i * i <= d; ++i){
        if(d % i) continue; 
        long long j = d/i; 
        
        // test i 
        long long added = i - (a % i); 
        if(added == i) added = 0; 

        long long lcm = (a+added)*(b+added)/gcd(a+added, b + added); 
        if(lcm < best){
            best = lcm; 
            ans = added;
        }

        added = j - (a % j); 
        if(added == j) added = 0; 
        lcm = (a+added)*(b+added)/gcd(a+added, b + added); 
        if(lcm < best){
            best = lcm; 
            ans = added;
        }    
    }
    cout << ans << "\n";
    return 0;
}