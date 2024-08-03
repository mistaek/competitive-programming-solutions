/*
958F2
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m; 
    vector<int> c(n); 
    for(int i = 0; i < n; ++i) cin >> c[i];

    int sat = 0;
    long long ans = 1e9, tot = 0;

    vector<int> obj(m+1), cnt(m+1, 0); 
    for(int i = 1; i <= m; ++i){ cin >> obj[i]; tot+= obj[i]; if(obj[i] == 0) ++sat;}

    if(tot > n){ cout << "-1\n"; return 0;}
    queue<int> q; 
    for(int i = 0; i < n; ++i){
        if(++cnt[c[i]] == obj[c[i]]) ++sat; 
        q.push(c[i]);

        while(!q.empty() && cnt[q.front()] > obj[q.front()]){ --cnt[q.front()]; q.pop();}
        if(sat == m){ ans = min(ans, (long long)q.size() - tot);}
    }

    if(ans == 1e9){
        cout << "-1\n"; 
    }
    else cout << ans << "\n";


    return 0;
}