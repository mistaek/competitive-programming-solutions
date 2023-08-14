/*
1775C
AC
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        long long n, x; cin >> n >> x; 
        if(n < x){
            cout << "-1\n";
            continue; 
        }
        if(n == x){
            cout << x << "\n"; 
            continue; 
        }
        if(x == 0){
            for(int i = 62; i>=0; i--){
                if(n & (1LL << i)){
                    cout << (1LL << (i+1)) << "\n"; 
                    break; 
                }
            }
            continue;
        }
        long long ans = 0; 
        for(int i = 62; i>=0; i--){
            if(x & (1LL << i) && !(n &(1LL<<i))){
                ans = -1; 
                break; 
            }
            if(n & (1LL << i) && (!(x &(1LL << i)))){

                if(ans == 0){
                    ans = -1; 
                    break; 
                }
                if(n & (1LL << (i+1))){
                    ans = -1; 
                    break;
                }
                for(int j = i; j >= 0; j--){
                    if(x & (1LL << j)){
                        ans = -1; 
                        break; 
                    }
                }
                if(ans == -1) break; 
                ans |= (1LL << (i+1));
                break; 
            }
            if(n &(1LL<<i)) ans |= (1LL <<i);
        }
        cout << ans << "\n";

    }
    return 0;
}