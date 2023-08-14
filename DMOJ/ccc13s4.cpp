#include <queue>
#include <cstdio>
#include <vector>

using namespace std; 
int main(){
    int n, m; 
    scanf("%d %d", &n, &m); 
    vector<int> tallerthan[n+1]; 
    while(m--){
        int tallr, shortr; 
        scanf("%d %d", &tallr, &shortr);
        tallerthan[tallr].push_back(shortr); 
    }
    int a, b; 
    bool printed = false;
    scanf("%d %d", &a, &b); 
    for(int i = 0; i < 2; i++){
        queue<int> q; 
        bool v[n] = {}; 
        if(i == 0){
            v[a] = true; 
            q.push(a); 
            while(!q.empty()){
                int s = a; 
                q.pop();
                vector<int>::iterator it;  
                for(it = tallerthan[s].begin(); it!= tallerthan[s].end(); it++){
                    q.push(*it); 
                    v[*it] = true; 
                }
            }
            if(v[b] == true){
                printf("yes");
                printed = true; 
                break; 
            }
        }   
        else{
            v[b] = true; 
            q.push(b); 
            while(!q.empty()){
                int s = b; 
                q.pop();
                vector<int>::iterator it;  
                for(it = tallerthan[s].begin(); it!= tallerthan[s].end(); it++){
                    q.push(*it); 
                    v[*it] = true; 
                }
            }
            if(v[a] == true){
                printf("no");
                printed = true; 
                break; 
            }
        }
    }
    if(!printed) printf("unknown"); 

    return 0; 
}