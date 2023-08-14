/*
1798D
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
        int n; cin >> n;
        vector<long long> a(n), pos, neg; 
        vector<long long> out; 
        long long mx = -1e9, mn = 1e9; 
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] >= 0) pos.push_back(a[i]); 
            else neg.push_back(a[i]);
            if(a[i] > mx) mx = a[i]; 
            if(a[i] < mn) mn = a[i];   
        }
        if(mx == mn){ cout << "no\n"; continue;}
        long long sum = 0;
        int i = 0, j = 0; 
        while(i < pos.size() || j < neg.size()){
            if(sum > 0){
                out.push_back(neg[j]); 
                sum += neg[j]; 
                j++; 
                
            }
            else{
                sum += pos[i];
                out.push_back(pos[i]); i++;
            }
        }
        cout << "yes\n"; 
        for(int k = 0; k < out.size(); k++){
            if(k) cout << " "; 
            cout << out[k]; 
        }
        cout << "\n";
    }
    return 0;
}