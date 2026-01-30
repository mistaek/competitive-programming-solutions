/*
2191D1
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int slen; cin >> slen;
        string s; cin >> s;

        vector<int> open(slen, 0);
        for(int i = 0; i < slen; ++i){
            if(i) open[i] = open[i-1];
            if(s[i] == '(') ++open[i];
            else --open[i];
        }

        int ans = -1;
        vector<int> lastm;
        if(open[0] > open[1]) lastm.push_back(0);
        for(int i = 1; i < slen-1; ++i){
            if(open[i] < open[i-1] && open[i] < open[i+1]) {
                lastm.push_back(open[i]);
                //cout << "Local minima " << i << " " << open[i] << "\n";
            }
            if(open[i] > open[i-1] && open[i] > open[i+1]) {
                lastm.push_back(open[i]);
                //cout << "Local maxima " << i << " " << open[i] << "\n";
            }
        }

        for(size_t i = 2; i < lastm.size(); i+=2){
            if(lastm[i] > lastm[i-1]+1) ans = slen-2;
        }

        if(lastm.size() >= 5) ans = slen-2;
        cout << ans << "\n";
    }
    return 0;
}