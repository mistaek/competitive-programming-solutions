/*
1998A
*/

#include <iostream>
#include <vector>

using namespace std; 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        vector<int> p(n);
        for(int i = 0; i < n; ++i){
            cin >> p[i];
        }

        for(int i = 0; i < n; ++i){
            if(i) cout << " "; 
            cout << p[(i+1)%n]; 
        }
        cout << "\n";
    }    
    return 0;
}