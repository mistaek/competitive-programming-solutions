/*
1864
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int x, y, n; 
        cin >> x >> y >> n;
        int a[n] = {};
        a[0] = x, a[n-1] = y;
        int diff = 1; 
        for(int i = n-2; i >= 1; i--){
            a[i] = a[i+1] - diff;
            diff++;
        }
        if(a[0] >= a[1] || a[1] - a[0] <= a[2] - a[1]) cout << "-1\n";
        else{
            for(int i = 0; i < n; i++){
                if(i) cout <<" ";
                cout << a[i];  
            }
            cout << "\n";
        }
        
    }
    return 0;
}