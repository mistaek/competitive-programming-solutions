/*
2165
*/

#include <iostream>
#include <vector>
using namespace std; 

int l1 = 1, l2 = 2, l3 = 3;
vector<pair<int, int>> ans; 
void solve(int n){
    if(n == 1){
        ans.push_back({l1, l3});
    }
    else{
        //want to move stack from l1 to l3, l2 is working stack
        swap(l2, l3); //l2 is now target, l3 is working
        solve(n-1); //everything is now at l3 
        ans.push_back({l1, l2}); //move bottom to l2
        //
        swap(l2, l3); //target is now l3, working l2
        swap(l1, l2); //start is now l2, working l1
        solve(n-1);
        swap(l1, l2); //swap back for anything in higher level (start is now l1 again)
    }
}
int main(){
    int n; cin >> n;
    solve(n);
    cout << ans.size() << "\n"; 
    for(auto& p : ans){
        cout << p.first << " " << p.second << "\n";
    }
    return 0;
}