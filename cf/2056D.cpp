/*
2056D
unsovled
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> a; 

vector<vector<int>> solve(int l, int r){
    int mid = (l+r)/2; 

    if(l == r){
        vector<vector<int>> ans(1, vector<int>(10,0));

        return 
    }
    vector<vector<int>> al = solve(l, mid), bl = solve(mid+1, r);

}
int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        a = vector<int>(n); 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }


    }
    return 0;
}