#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string in; cin >> in; 

    set<int> zero, one; 
    for(int i = 0; i < in.length(); ++i){
        if(in[i] == '0') zero.insert(i+1);
        else one.insert(i+1);
    }

    vector<vector<int>> subs; 
    while(!zero.empty()) {
        vector<int> sub; 
        int cur = *zero.begin();
        sub.emplace_back(*zero.begin());
        zero.erase(zero.begin());
        while(true)
        {
            auto nxt1 = one.lower_bound(cur);
            if(nxt1 == one.end()) break; 
            auto nxt0 = zero.lower_bound(*nxt1);
            if(nxt0 == zero.end()) break;

            sub.emplace_back(*nxt1); sub.emplace_back(*nxt0); 
            one.erase(nxt1);
            cur = *nxt0;
            zero.erase(nxt0);
        }
        subs.emplace_back(std::move(sub));
    }
    
    if(zero.empty() && one.empty()){
        cout << subs.size() << "\n"; 
        for(auto v : subs){
            cout << v.size();
            for(auto idx : v) cout << " " << idx; 
            cout << "\n";
        }
    }
    else cout << "-1\n";


    return 0;
}