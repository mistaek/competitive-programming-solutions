/*
1846G
AC
*/

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int bstoi(string s){
    int ans = 0, pow = 1;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '1') ans+= pow; 
        pow *= 2; 
    }
    return ans; 
}

int rem(int a, int b){
    //removes conditions a from b
    for(int i = 0; i <= 10; i++){
        if((a & (1 << i)) && (b & (1 << i))) b -= (1 << i); 
    }
    return b; 
}

int add(int a, int b){
    //adds conditions a to b
    return b |= a; 
}

int main(){
    cin.tie(0); 
    ios::sync_with_stdio(false); 
    int t; cin >> t; 
    while(t--){
        int n, m; cin >> n >> m; 
        string s;
        int start; 
        cin >> s; start = bstoi(s); 
        vector<pair<int, pair<int, int>>> e; 
        for(int i = 0; i < m; i++){
            int c; cin >> c; 
            string u, v; 
            cin >> u >> v; 
            e.push_back({c, {bstoi(u),bstoi(v)}}); 
        }
        sort(e.begin(), e.end()); //take shorter paths first. shouldn't really matter. 
        int dist[1025] = {};
        //djikstra
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> djs; 
        djs.push({0, start});  
        for(int i = 0; i <= 1024; i++) dist[i] = -1;  
 

        while(!djs.empty()){
            pair<int, int> top = djs.top(); 
            djs.pop(); 
            if(dist[top.second] != -1 && dist[top.second] <= top.first) continue; 
            else{
                //cout << "Reached " << top.second << " in " << top.first << "\n"; 
                dist[top.second] = top.first; 
                for(pair<int, pair<int, int>> edge : e){
                    int dest = add(edge.second.second, rem(edge.second.first, top.second)); 
                    if(dist[dest] == -1 || dist[dest] > (dist[top.second] + edge.first)) djs.push({dist[top.second] + edge.first, dest}); 
                    //cout << "Pushed (" << dist[top.second] + edge.first << ", " << dest << ")\n"; 
                }
            }
        }
        cout << dist[0] << "\n"; 
    }
    return 0;  
}