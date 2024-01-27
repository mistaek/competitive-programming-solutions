/*
1922E
AC, dumb problem
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<long long> out; 

long long sumto(long long t, long long base){
    long long i, j; 
    for(i = 1; i <= 60; i++){
        if((1LL << i) > t){
            j = i-1; 
            t -= (1LL << j); 
            break; 
        }
    }

    for(i = 0; i < j; i++) out.push_back(base + i); 
    -- i; //i is now j-1
    while(t && i >= 0){
        if((1LL << i)  <= t){
            out.push_back(base + i); 
            t -= (1LL << i); 
        }
        --i; 
    }
    
    return t; 
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0); 
    int t; cin >> t; 
    while(t--){
        long long x; cin >> x; 
        long long base = 20000;
        out.clear();
        
        while(x){
            x = sumto(x, base);
            //cout << x << " " << base << "\n"; 
            base -= 200;
        }       
        
        if(out.size() > 200) cout << -1 << "\n"; 
        else cout << out.size() << "\n";
        for(int i = 0; i < out.size(); i++){
            if(i) cout << " "; 
            cout << out[i]; 
        }
        cout << "\n";
    }
    return 0;
}