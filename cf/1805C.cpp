/*
1805C
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m;
        vector<long long> hwy; 

        
        for(int i = 0; i < n; i++){
            long long k; cin >> k; 
            hwy.push_back(k); 
        }
        sort(hwy.begin(), hwy.end()); 
        for(int i = 0; i < m; i++){
            long long a, b, c; 
            cin >> a >> b >> c; 
            if(c <= 0) cout << "no\n";
            else{
                auto it = lower_bound(hwy.begin(), hwy.end(), b);
                if(it == hwy.end()) it--; 
                if((b-*it) * (b-*it) < 4 * a * c){
                    cout << "yes\n"; 
                    cout << *it << "\n"; 
                }
                else{
                    if(it != hwy.begin()){
                        it--; 
                        if((b-*it) * (b-*it) < 4 * a * c){
                            cout << "yes\n"; 
                            cout << *it << "\n"; 
                        }
                        else cout << "no\n";
                    }
                    else cout << "no\n"; 
                }
            }
        }
    }
    return 0;
}