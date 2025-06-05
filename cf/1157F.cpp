/*
1157F
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map> 
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    int n; cin >> n; 
    vector<int> a(n);
    map<int, int> cnt;  
    for(int i = 0; i < n; ++i){
        cin >> a[i]; 
        cnt[a[i]]++; 
    }

    sort(a.begin(), a.end()); 
    
    auto it = cnt.begin(); 
    int curSize = it->second, curStart = it->first;
    int best = curSize, bestStart = it->first;
    while(it != cnt.end()){
        auto nxt = next(it); 
        if(nxt == cnt.end()) break; 
        if(nxt->first == it->first + 1 && (it->second > 1 || curStart == it->first)){
            //can add
            curSize = curSize + nxt->second;
        }
        else if(nxt->first == it->first + 1){
            //start new circle at cur
            curSize = it->second + nxt->second; curStart = it->first; 
        }
        else{
            curSize = nxt->second; curStart = nxt->first; 
        }
        if(curSize > best){
            //cout << "Found " << curSize << " at " << curStart << "\n";
            best = curSize; 
            bestStart = curStart; 
        }

        it = nxt;
    }

    cout << best << "\n"; 
    vector<int> ans(best); 
    int idx = lower_bound(a.begin(), a.end(), bestStart) - a.begin(); 

    int turn = 0;
    for(int i =0 ; i < best; ++i){
        if(turn){
            ans[best - (i-1)/2 - 1] = a[idx+i]; 
        }
        else{
            ans[i/2] = a[idx + i];
        }
        turn = 1-turn;
    }

    for(int i = 0; i < best; ++i){
        if(i) cout << " "; 
        cout << ans[i];
    }
    cout << "\n";
    return 0;
}