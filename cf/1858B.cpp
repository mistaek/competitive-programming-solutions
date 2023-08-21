/*
1858B
AC, got lost in the sauce
*/

#include <iostream>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 

    int t; cin >> t; 
    while(t--){
        int d, n, m; cin >> n >> m >> d;
        long long s[m]; 
        for(int i = 0; i < m; i++){
            cin >> s[i];
        }

        long long b[m] = {}; //cookies up to this point
        if(s[0] > 1) b[0]++;
        for(int i = 0; i < m; i++){
            if(i == 0){
                b[i] += (s[i]-2)/d + 1; 
            }            
            else{
                b[i] = b[i-1] + (s[i] - s[i-1]-1)/d + 1;
            }
            //cout << b[i] << " "; 
        }
        
        long long total = b[m-1] + (n-s[m-1])/d, minimum = total;
        //cout << total << "\n";
        long long cur = m; 

        for(int i = 0; i < m; i++){
            long long newtot = 0;
            if(i == 0){
                newtot = total - b[i+1] + ((s[i+1] - 2)/d) + 2; 
            }
            else if(i == m-1){
                newtot = b[i-1] + ((n - s[i-1])/d); 
            }
            else{
                newtot = total - b[i+1] + b[i-1] + (s[i+1] - s[i-1] -1)/d + 1; 
            }
            if(newtot == minimum){
                if(minimum == total) continue; 
                else{
                    cur++; 
                }
            }
            else if(newtot < minimum){
                minimum = newtot; 
                cur = 1; 
            }
            //cout << newtot << " "; 
        }
        //cout << "\n";
        cout << minimum << " " << cur << "\n";
    }
}