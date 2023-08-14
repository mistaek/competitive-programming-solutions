/*
1783C
ac
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
        vector<int> prep(n), copy(n);
        for(int i = 0; i < n; i++){
            cin >> prep[i]; 
            copy[i] = prep[i]; 
        }
        sort(copy.begin(), copy.end());
        int sum = 0; 
        int maxw = 0; 
        for(int i = 0; i < n; i++){
            sum += copy[i];
            if(sum <= m) maxw = i+1; 
            else{
                sum -= copy[i];
                break; 
            }
        }
        int pl = n - maxw + 1; 
        if(0 < maxw && maxw < n){
            if(sum - copy[maxw-1] + prep[maxw] <= m) pl--;
        }
        cout << pl <<"\n";
    }
    return 0;
}