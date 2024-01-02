/*
1902E
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 


int ptrie[1000001][26] = {};
long long cnt[10000001] = {};
int idx = 0;

void add(const string &s){
    // add to trie
    int i = 0;//start 
    for(auto c : s){
        if(ptrie[i][c-'a'] == 0){
            ptrie[i][c-'a'] = ++idx; 
        }
        i = ptrie[i][c-'a'];
        cnt[i]++;
    }
}
long long match(const string &s){
    int i = 0; 
    long long ans = 0;
    for(auto c : s){
        if(ptrie[i][c-'a']){
            i = ptrie[i][c-'a'];     
        }
        else break; 
        ans += cnt[i];
    }
    return ans; 
}

int main(){
    int n; cin >> n;
    long long ans = 0;
    string s[n];
    
    for(int i = 0; i < n; i++){
        cin >> s[i]; 
        add(s[i]); 
        ans += 2 *n * (long long)s[i].length();
    }
    for(int i = 0; i < n; i++){
        reverse(s[i].begin(), s[i].end());
        ans -= 2 * match(s[i]);
    }
    cout << ans << "\n";


    return 0;
}