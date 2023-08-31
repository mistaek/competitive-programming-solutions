/*
1864
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){ 
    int t; 
    cin >> t; 
    while(t--){
        int n, k; 
        cin >> n >> k;
        if(k % 2){
            vector<char> a, b; 
            for(int i = 0; i < n; i++){
                char c; cin >> c; 
                if(i % 2) b.push_back(c); 
                else a.push_back(c); 
            }
            sort(a.begin(), a.end()); 
            sort(b.begin(), b.end()); 
            for(int i = 0; i < n; i++){
                if(i%2) cout << b[(i-1)/2];
                else cout << a[i/2];
            }
        }
        else{
            vector<char> s(n); 
            for(int i = 0; i < n; i++){
                cin >> s[i]; 
            }
            sort(s.begin(), s.end());
            for(int i = 0; i < n; i++){
                cout << s[i];
            }
        }
        cout << "\n";
    }
    return 0;
}