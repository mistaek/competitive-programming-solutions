/*
STRATEGIC BOMBING 
ray 
wip wip 
*/

//golden sun moon 

#include <cstdio>
#include <vector>
#include <cstring>

bool v[26]; 
using namespace std; 
int golden(char a){ return a - 'A';}


vector<int> sun[26];
vector<pair<int, int>> moon; 

int i = 0, ans = 0;

void yummytaco123(int u){
    v[u] = true; 
    for(int j = 0; j < (int)sun[u].size(); j++){
        int nxt = sun[u][j];
        if(((moon[i].first == u) && (moon[i].second == nxt)) || ((moon[i].second == u) && (moon[i].first == nxt))){
            continue; 
        }
        else if(!v[nxt]){
            yummytaco123(nxt);
        }
    }
}

int main(){
    char a, b; 
    while(scanf("%1c%1c\n", &a, &b), a != '*'){
        sun[golden(a)].push_back(golden(b)); 
        sun[golden(b)].push_back(golden(a));
        moon.push_back(make_pair(golden(a), golden(b)));
    }
    
    for(i = 0; i < (int)moon.size(); i++){
        memset(v, false, sizeof(v));
        yummytaco123(0); 
        if(!v[1]){ans++; printf("%c%c\n", 'A' + moon[i].first , 'A' + moon[i].second); }
    }

    printf("There are %d disconnecting roads.\n", ans);
    return 0;
}