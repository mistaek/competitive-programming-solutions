/*
1925A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std; 

string s, out; 
int n, k, m; 

//check if [idx, m) satisfies cn
bool check(int cn, int idx){ 
    if(cn == 0) return ""; 
    vector<int> a(k, 0);
    int app = 0;
    for(int i = idx; i < m; i++){
        if(a[s[i] - 'a'] == 0) ++app; 
        a[s[i] - 'a'] = 1; 
        if(app == k){
            out.push_back(s[i]);
            return check(cn-1, i+1);
        }
    }
    
    for(int i = 0; i < k; i++){
        if(a[i] == 0){
            while(out.length() < n){
                out.push_back((char)('a' + i));
            }
            return false; 
        }
    }
    return false; 
}
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0); 

    int t; cin >> t; 
    while(t--){
        cin >> n >> k >> m; 
        cin >> s; 
        out.clear();

        if(check(n, 0)) cout << "YES\n"; 
        else cout << "NO\n" << out << "\n";
        
    }
    return 0;
}