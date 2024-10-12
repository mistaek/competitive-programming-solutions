/*
2002C.cpp
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n;
        vector<pair<long long, long long>> pts(n);
        for(int i = 0; i < n; ++i){
            cin >> pts[i].first >> pts[i].second;
        }

        pair<long long, long long> s, f; 
        cin >> s.first >> s.second >> f.first >> f.second;
        long long tobeat = (s.first - f.first) * (s.first - f.first); 
        tobeat += (s.second - f.second) * (s.second - f.second); 
        
        bool pos = 1; 
        for(int i = 0; i < n;++i){
            long long dist = (pts[i].first - f.first) * (pts[i].first - f.first); 
            dist += (pts[i].second - f.second) * (pts[i].second - f.second); 
            if(dist <= tobeat) pos = 0;
        }

        if(pos) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}