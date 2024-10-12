/*
979D
(with editorial and memory leak)
*/

#include <iostream>
#include <vector>
#include <memory>
using namespace std; 

struct TrieNode;
using tn = TrieNode*;

int n = 1e5+1;
struct TrieNode
{
    int mi= 1e9; // smallest member of this branch 
    tn nxt[2] = {}; // bits 0 , 1
};

vector<tn> roots; 
bool added[100001] = {};

vector<vector<int>> divisors(n);

void add(int k, int u){
    TrieNode* cur = roots[k];
    cur->mi = min(cur->mi, u);
    for(int i = 20; i >= 0; --i){
        int bit = (u >> i) & 1;
        if(cur->nxt[bit] == nullptr){
            cur->nxt[bit] = new TrieNode;
        }
        cur = cur->nxt[bit];
        cur->mi = min(cur->mi, u);
    }
}

int query(int x, int k, int s){
    TrieNode* cur = roots[k];

    if(cur->mi > s-x) return -1;

    int ans = 0;
    for(int i = 20; i >= 0; --i){
        //whenever possible take path opposite of x
        int bit = (x >> i) &1; // is bit 0 or 1?
        
        if(cur->nxt[1-bit] != nullptr && cur->nxt[1-bit]->mi <= s-x){
            ans += ((1-bit)<< i);
            cur = cur->nxt[1-bit];
        }
        else{
            if(cur->nxt[bit] == nullptr){
                return -1;
            }
            ans += (bit << i);
            cur = cur->nxt[bit];
        }
    }
    return ans;
}
int main(){
    // nln 
    for(int i = 1; i <= n; ++i){
        for(int j = i; j <= n; j += i){
            divisors[j].push_back(i);
        }
        roots.push_back(new TrieNode);
    }

    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int q; cin >> q; 
    while(q--){
        int t; cin >> t; 
        if(t == 1){
            int u; cin >> u; 
            if(added[u]) continue; 
            for(int k : divisors[u]){
                add(k, u);
            }
            added[u] = 1;
        }
        else{
            int x, k, s; cin >> x >> k >> s; 
            if(x % k  || x >= s) cout << "-1\n"; 
            else {
                cout << query(x, k, s) << "\n";
            }
        }
    }
    return 0;
}