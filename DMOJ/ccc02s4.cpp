/*
ccc 02s4 cross the bridge u dummies
ray
ac -POG
*/

#include <string>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std; 

int m, q;
pair<int, string> ppl[105]; 
int parent[105], child[105], dp[105];
int maxt[105][105]; 

int main(){
    //do later, am lazy and sad!
    scanf("%d %d", &m, &q);
    for(int i = 1; i <=q; i++){
        cin >> ppl[i].second >> ppl[i].first;
        //printf("%d ", ppl[i].first);
        dp[i] = 1e9;
    }
    //printf("\n");
    for(int i = 1; i <= q; i++){
        for(int j = i; j<= q; j++){
            maxt[i][j] = max(ppl[j].first, maxt[i][j-1]);
            //printf("max from %d to %d was compared between %d and %d\n", i, j, ppl[j].first, maxt[i][j-1]);
        }
    }

    parent[0] = 0; 
    dp[0] = 0; 

    for(int i = 1; i <= q; i++){
        for(int j = 1; j <= m; j++){
            if(i - j >= 0){
                if(dp[i-j] + maxt[i-j+1][i] < dp[i]){
                    dp[i] = dp[i-j] + maxt[i-j+1][i];
                    //printf("using %d and max from %d to %d which is %d, optimal at %d is %d\n", i-j, i-j+1, i,maxt[i-j+1][i], i, dp[i]);

                    parent[i] = i-j; 
                }
            }
        }
    }
    printf("Total Time: %d\n", dp[q]);
    int traverser = q;child[q] = -1; 
    while(traverser != 0){
        child[parent[traverser]] = traverser; 
        traverser = parent[traverser];
    }
    //for(int i = 0; i <= q; i++) printf("%d ", child[i]);
    //printf("\n");
    while(traverser != -1){
        for(int i = traverser+1; i <= child[traverser]; i++){
            if(i > traverser+1) cout << " "; 
            cout << ppl[i].second; 
        }
        cout << "\n";
        traverser = child[traverser];
        
    }
    
    


    
    return 0; 
}