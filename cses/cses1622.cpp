/*
1622
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std; 

vector<string> ans; 
int main(){
    string s; cin >> s; 
    sort(s.begin(), s.end());

    do{
        ans.push_back(s);
    }while(next_permutation(s.begin(), s.end())); 

    cout << ans.size() << "\n"; 
    for(auto& str : ans) cout << str << "\n";
    return 0;
}
