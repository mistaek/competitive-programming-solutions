/*
UVa 10305
ray 
doge (probs AC, uva judges are sooooo slow to update these days)
*/

#include <cstdio>
#include <vector>
int n, m;

using namespace std; 

vector<int> adjl[101];
bool v[101] = {};
vector<int> ans; 

void dfs(int t){
    //t for task!
    //b for bee!
    //m for whisky!
    v[t] = true;            
    for(auto it = adjl[t].begin(); it != adjl[t].end(); it++){
        if(!v[*it]){
            dfs(*it);
        }
    }
    ans.push_back(t);
}
int main(){
    while(scanf("%d %d", &n, &m), n){
        ans.clear();
        for(int i = 0; i < 101; i++){
            adjl[i].clear();
            v[i] = false;
        }

        for(int i = 0; i < m; i++){
            int a, b; scanf("%d %d", &a, &b); 
            adjl[a].push_back(b);
        }
        /*for(int i = 1; i<= n; i++){
            printf("Task %d:", i); 
            for(auto it = adjl[i].begin(); it!= adjl[i].end(); it++){
                printf(" %d", *it);
            }
            printf("\n");
        }*/
        for(int i = 1; i <= n; i++){
            if(!v[i]) dfs(i);
        }

        for(vector<int>::reverse_iterator r = ans.rbegin(); r!= ans.rend(); r++){
            if(r != ans.rbegin()) printf(" %d", *r); 
            else printf("%d", *r);
        }
        printf("\n");   
    }
    return 0;
}