/*
1847D
AC
*/

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

using namespace std; 

int main(){
    int n, m, q; cin >> n >> m >> q; 
    string str; cin >> str; 
    int s[n], numOnes = 0; 
    set<int> notIn, curOnes;
    vector<int> newOrder; 
    for(int i = 0; i < n; i++){
        s[i] = str[i] - '0';
        notIn.insert(i);    
        numOnes += s[i];
    }
    //cout << numOnes << "\n";
    for(int i = 0; i < m; i++){
        int l, r; cin >> l >> r; 
        --l; --r; 
        auto it = notIn.lower_bound(l);
        if(it == notIn.end() || *it > r) continue; 
        while(it != notIn.end() && *it <= r){
            newOrder.push_back(*it); 
            //cout << *it << " ";
            it = notIn.erase(it);
        }
    }

    //cout << "\n";
    int ans = 0;

    for(int i = 0; i < min(numOnes, (int)newOrder.size()); i++){
        curOnes.insert(newOrder[i]); 
        if(s[newOrder[i]] == 0) ++ans;
    }

    for(int i = 0; i <q; ++i){
        int x; cin >> x; 
        --x; 
        if(s[x] == 1){
            if(numOnes - 1 < newOrder.size() && s[newOrder[numOnes-1]] == 0) --ans; //swap no longer needed for last
            if(numOnes - 1 < newOrder.size()) curOnes.erase(newOrder[numOnes-1]);
            if(curOnes.find(x) != curOnes.end()) ++ans; //if one of the slots we want to fill turned to 0, need new swap
            s[x] = 0;
            --numOnes; 
        }
        else if(s[x] == 0){
            s[x] = 1;
            ++numOnes; 
            if(numOnes - 1 < newOrder.size() && s[newOrder[numOnes-1]] == 0) ++ans; //need swap for new one
            if(curOnes.find(x) != curOnes.end()) --ans; //no swap needed to replace previous
            if(numOnes - 1 < newOrder.size()) curOnes.insert(newOrder[numOnes-1]);
            ans = max(ans, 0);

        }
        cout << ans << "\n";
    }

    
    return 0;
}