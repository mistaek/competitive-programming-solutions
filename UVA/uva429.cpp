/*
UVa 429
Ray
AC
*/

//bfs sssp

#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <queue>
#include <sstream> 

using namespace std; 

int main(){
    int n; scanf("%d\n\n", &n); 
    while(n--){
        vector<string> dict; 
        string word; 
        while (getline(cin, word), word[0] != '*'){
            dict.push_back(word); 
        }

        map<string, int> nodes; 
        for(int i = 0; i < dict.size(); i++) nodes[dict[i]] = i; 

        vector<int> adjl[201]; 
        
        for(int i = 0; i < dict.size(); i++){
            
            for(int j = 0; j < dict.size(); j++){
                if(dict[i].length() == dict[j].length() && i != j){
                    int count = 0; 
                    for(int k = 0; k < dict[i].length(); k++){
                        if(dict[i][k] != dict[j][k]) count++; 
                    }
                    if(count == 1) adjl[i].push_back(j);
                }
            }
        }
        string line; 
        stringstream ss;  
        while(getline(cin, line), line.length() > 2){
            ss.clear(); 
            ss << line; 
            string word1, word2; 
            ss >> word1 >> word2; 
            queue<int> q; q.push(nodes[word1]); 
            vector<int> dist(201, -1); dist[nodes[word1]] = 0; 
            while(!q.empty()){
                int v = q.front(); q.pop(); 
                for(int u : adjl[v]){
                    if(dist[u] == -1){
                        dist[u] = dist[v] +1; 
                        q.push(u); 
                    } 
                }
            }
            cout << word1 << " " << word2 << " " << dist[nodes[word2]] << "\n";

        }
        if(n) cout << "\n";

        
    }
    return 0;
}