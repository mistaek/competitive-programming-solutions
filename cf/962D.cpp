/*
962D
AC
*/

#include <iostream>
#include <set>
#include <vector>

using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int n; cin >> n; 

    set<pair<long long, long long>> s; 
    vector<long long> out(n, 0); 
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        s.insert({a, i});
    }

    auto cur = s.begin();
    while(cur != s.end() && next(cur) != s.end()){
        if(next(cur)->first == cur->first)
        {
            auto save = *next(cur); 
            cur = s.erase(cur); // = next
            cur = s.erase(cur); 
            save.first *= 2; 
            s.insert(save); 
            save.first /=2; 
            cur = s.lower_bound(save);
        }
        else
        {
            cur = next(cur);
        }
    }

    for(auto p : s)
    {
        out[p.second] = p.first;
    }
    cout << s.size() << "\n"; 
    bool space = false;
    for(int i = 0; i < n; ++i){
        if(out[i]){
            if(space) cout << " "; 
            cout << out[i];
            space = true;
        }
    }
    cout << "\n";
    return 0;
}