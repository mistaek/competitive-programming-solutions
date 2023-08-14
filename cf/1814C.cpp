/*
1814C
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
        int n, s1, s2; cin >> n >> s1 >> s2; 
        vector<pair<int, int>> freq; 
        for(int i = 1; i <= n; i++){
            int f; cin >> f; 
            freq.push_back({f, i});
        }
        sort(freq.rbegin(), freq.rend());

        int cnt = 0, t1 = s1, t2 = s2; 
        vector<int> a1, a2; 

        while(cnt < n){
            if(t1 <= t2){
                a1.push_back(freq[cnt].second);
                t1 += s1; 
            }
            else{
                a2.push_back(freq[cnt].second); 
                t2 += s2; 
            }
            cnt++;
        }
        cout << a1.size(); 
        for(int i = 0; i < a1.size(); i++){
            cout << " "; 
            cout << a1[i]; 
        }
        cout << "\n";
        cout << a2.size();
        for(int i = 0; i < a2.size(); i++){
            cout << " "; 
            cout << a2[i]; 
        }
        cout << "\n";
    }
    return 0;
}