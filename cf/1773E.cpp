/*
1773E
AC
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n; cin >> n;
    vector<vector<int>> towers(n); 
    vector<int> arr; 
    for(int i = 0; i < n; i++){
        int k; cin >> k; 
        for(int j = 0; j < k; j++){
            int in; cin >> in; 
            arr.push_back(in); 
            towers[i].push_back(in);
        }
    }
    sort(arr.begin(), arr.end());
    map<int, int> follow; 
    for(int i = 0; i < arr.size() - 1; i++){
        follow[arr[i]] = arr[i+1];
    }

    int s = 0;
    for(int i = 0; i < n; i++){
        for(int j = 1; j < towers[i].size(); j++){
            if(towers[i][j] != follow[towers[i][j-1]]) s++;
        }
    }
    cout << s << " " << s + n - 1 << "\n";
    return 0;
}