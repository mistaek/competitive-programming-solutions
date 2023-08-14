/*
1810D
AC
*/

#include <iostream>
#include <algorithm>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);

    int t; cin >> t; 
    while(t--){
        int q; cin >> q; 
        long long minh = 1, maxh = 1e18;
        for(int i = 0; i < q; i++){
            if(i) cout << " ";
            //cout << "\n";
            int qt; cin >> qt; 
            if(qt == 1){
                long long a, b, n; cin >> a >> b >> n;
                long long qminh, qmaxh; 
                if(n == 1){
                    qminh = 1; 
                    qmaxh = a; 
                }
                else{
                    qminh = ((n-1) * a) - ((n-2)*b) + 1; 
                    qmaxh = (n*a) - ((n-1) * b);
                }
                if(qminh > maxh || qmaxh < minh){
                    cout << 0;
                }
                else{
                    cout << 1;
                    minh = max(minh, qminh); 
                    maxh = min(maxh, qmaxh);
                }
            }
            else{
                long long a, b; cin >> a >> b; 
                
                long long kmin = minh - b;
                kmin += a-b-1; 
                kmin /= a-b;
                long long kmax = maxh - b; 
                kmax += a-b -1; 
                kmax /= a-b; 
                if(a >= minh) kmin = 1; 
                if(a >= maxh) kmax = 1; 
                //cout << minh << " " << maxh << " " << a << " " << b << " " << kmin << " " << kmax <<"\n";
                if(kmin == kmax){
                    cout << kmax;
                }
                else cout << -1; 
            }
        }
        cout << "\n";
    }
    return 0;
}