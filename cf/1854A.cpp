/*
1854A1/2
*/

#include <iostream>
#include <algorithm>

using namespace std; 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        int a[n]; 
        int maxp = 0, maxn = 0, pos = 0, neg = 0; 
        int maxpi= 0, maxni=0; 
        for(int i = 0; i < n; i++){
            cin >> a[i]; 
            if(a[i] > maxp){ maxp = a[i]; maxpi = i; }
            if(a[i] > 0) pos++; 
            if(a[i] < 0) neg++;
            if(a[i] < maxn){ maxn = a[i]; maxni = i;}
        }
        if(abs(maxn) > maxp){
            if(pos < 13){
                cout << pos + n - 1 << "\n"; 
                for(int i = 0; i < n; i++){
                    if(a[i] > 0) cout << i+1 << " " << maxni +1 << "\n"; 
                }
                for(int i = n-1; i>= 1; i--){
                    cout << i << " " << i+1 << "\n"; 
                }
            }
            else{
                cout << 5 + neg + n-1 << "\n"; 
                for(int i = 0; i < 5; i++){
                    cout << maxpi+1 << " " << maxpi +1<< "\n"; 
                }
                for(int i = 0; i < n; i++){
                    if(a[i] < 0) cout << i+1 << " " << maxpi+1 << "\n"; 
                }
                for(int i = 2; i <= n; i++){
                    cout << i << " " << i-1 << "\n"; 
                }
            }
        }
        else{
            if(neg < 13){
                cout << neg + n-1 << "\n"; 
                for(int i = 0; i < n; i++){
                    if(a[i] < 0) cout << i+1 << " " << maxpi+1 << "\n"; 
                }
                for(int i = 2; i <= n; i++){
                    cout << i << " " << i-1 << "\n"; 
                }
            }
            else{
                cout << 5 +  pos + n-1 << "\n"; 
                for(int i = 0; i < 5; i++){
                    cout << maxni+1 << " " << maxni +1<< "\n"; 
                }
                for(int i = 0; i < n; i++){
                    if(a[i] > 0) cout << i+1 << " " << maxni +1 << "\n"; 
                }
                for(int i = n-1; i>= 1; i--){
                    cout << i << " " << i+1 << "\n"; 
                }
            }
        }
        

    }
    return 0;
}