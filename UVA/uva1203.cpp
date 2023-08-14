// uva 1203 by valuepaw369 aka epiccoder42069

#include <cstdio>
#include <queue> 
#include <vector>

using namespace std; 

int main(){
    char str[10];
    vector<pair<int,int>> perquer;   
    while(scanf(" %s", &str[0]), str[0] != '#'){
        int per, quer; 
        scanf("%d %d", &quer, &per); 
        perquer.push_back(make_pair(per, quer));
    }
    // process
    int k; 
    scanf(" %d", &k); 
    int t = 1; 
    priority_queue<int, vector<int>, greater<int>> pq; 
    while(k){   
        for(auto it = perquer.begin(); it!=perquer.end(); it++){
            if(t % it->first  == 0){
                pq.push(it->second); 
            }
        }
        while(!pq.empty()){
            printf("%d\n", pq.top());
            pq.pop(); 
            k--;
            if(k == 0) break; 
        }
        t++;
    }

    return 0; 
}