/*
2176E
*/

#include <iostream>
#include <list>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct link {
    long long a;
    long long c;
    int idx;

    bool operator<(const link& b) {
        if(c < b.c) return true;
        if(c == b.c && a > b.a) return true;
        return false;
    }
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;

        vector<link> links(n), svlinks(n);
        vector<int> zeroes(n), cost(n, 0), removed(n, 0);
        for(int i = 0; i < n; ++i) {
            links[i].idx = i;
            cin >> links[i].a;
        }

        for(int i = 0; i < n; ++i){
            cin >> links[i].c;
        }
        for(int i = 0; i < n; ++i){
            cin >> zeroes[i];
        }
        svlinks = links;
        list<link> og, save;
        map<int, list<link>::iterator> mp, mp2;
        for(int i = 0; i < n; ++i) {
            og.push_back(links[i]);
            mp[i] = prev(og.end());
        }
        for(int i = 0; i < n; ++i) {
            save.push_back(links[i]);
            mp2[i] = prev(save.end());
        }

        sort(links.begin(), links.end());

        long long ans = 0;
        for(int i = 0; i < n; ++i) {
            if(mp.find(links[i].idx) == mp.end()) continue;
            auto it = mp[links[i].idx];
            while(it != og.begin()){
                auto p = prev(it);
                if(p->a <= it->a){
                    ans += it->c;
                    cost[p->idx] = it->c;
                    mp.erase(p->idx);
                    og.erase(p);
                }
                else break;
            }
            while(next(it) != og.end()) {
                auto p = next(it);
                if(p->a <= it->a) {
                    ans += it->c;
                    cost[p->idx] = it->c;
                    mp.erase(p->idx);
                    og.erase(p);
                }
                else break;
            }
            if(og.size() > 1){ 
                ans += it->c;
                cost[it->idx] = it->c;
                mp.erase(it->idx);
                og.erase(it);
            }
        }
        cout << ans;

        for(int i = 0; i < n; ++i){
            cout << " ";
            int idx = zeroes[i]-1;
            auto it = save.begin();
            if(save.size() == 0){ 
                cout << 0; 
                continue;
            }
            // cout << "Zeroing " << idx << " " << svlinks[idx].a << " " << svlinks[idx].c << "\n";

            if(removed[idx]) {
                auto it2 = mp2.lower_bound(idx);
                if(it2 == mp2.end()) {
                    it = save.insert(save.end(), svlinks[idx]);
                }
                else {
                    it = save.insert(it2->second, svlinks[idx]);
                }
            }
            else it = mp2[idx];
            //cout << "Verify: " << it->a << " " << it->c << "\n";
            while(it != save.begin()){
                auto p = prev(it);
                if(p->a <= it->a){
                    ans -= cost[p->idx];
                    cost[p->idx] = 0;
                    removed[p->idx] = 1;
                    // cout << "Zeroed " << p->idx << " with value " << p->a << " and cost " << cost[p->idx] << "\n";
                    mp2.erase(p->idx);
                    save.erase(p);
                }
                else break;
            }
            while(next(it) != save.end()) {
                auto p = next(it);
                if(p->a <= it->a) {
                    ans -= cost[p->idx];
                    cost[p->idx] = 0;
                    removed[p->idx] = 1;
                    // cout << "Zeroed " << p->idx << " with value " << p->a << " and cost " << cost[p->idx] << "\n";

                    mp2.erase(p->idx);
                    save.erase(p);
                }
                else break;
            }
            ans -= cost[it->idx];
            cost[it->idx] = 0;
            removed[it->idx] = 1;
            mp2.erase(it->idx);
            save.erase(it);
            cout << ans;
        }
        cout << "\n";
    }
    return 0;
}