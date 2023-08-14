/*
1835A
*/

#include <iostream>
#include <algorithm>
using namespace std;

int gmin(int d){
    int ans = 1; 
    for(int i = 1; i < d; i++){
        ans *= 10; 
    }
    return ans;
}
int gmax(int d){
    return gmin(d+1) -1; 
}


int main(){
    ios_base::sync_with_stdio(false); 

    cin.tie(NULL); 
    int t; cin >> t; 
    while(t--){
        
        long long a, b, c, k; cin >> a >> b >> c >> k; 
        
        if(c > max(a+1, b+1) || c < max(a, b)) cout << -1 << "\n"; 
        else{
            int amin = gmin(a), amax = gmax(a);
            bool ans = true; 
            for(; amin <= amax; amin++){

                int bmin, bmax;
                bmin = max(gmin(b), gmin(c) - amin);
                bmax = min(gmax(b), gmax(c) - amin);
                if(bmin > bmax) continue;
                int have = bmax - bmin +1;              
                
                if(have >= k){
                    cout << amin << " + " << bmin + k -1 << " = " << amin + bmin + k -1 << "\n";
                    ans = false; 
                    break;
                }
                k -= have; 
            }
            if(ans) cout << "-1\n"; 
            
        }
        

    }
    return 0;
}