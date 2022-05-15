/*
DMOPC 15 C6 P4  
Ray
ac
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std; 

vector<pair<int, pair<int, int>>> el; 

//will look at class implementation after

int p[100001], r[100001]; // ufds  

int getleader(int v){
    if(p[v] != v) return p[v] = getleader(p[v]);
    else return v;
}

bool sameset(int a, int b){
    if(getleader(a) == getleader(b)) return true; 
    else return false; 
}

void merge(int a, int b){
    if(!sameset(a,b)){
        int x = getleader(a), y = getleader(b); 
        if(r[x] > r[y]){
            p[y] = x; 
        }
        else if(r[y] > r[x] ) p[x] = p[y];
        else{
            p[x] = p[y]; 
            r[y]++;
        }
    }
    else return;
}

int main(){
    int n, k; 
    scanf("%d %d", &n, &k);
    for(int i = 1; i < n; i++){
        int c; scanf("%d", &c); 
        el.push_back(make_pair(c, make_pair(i, i+1)));
        if(i <= n-k) el.push_back(make_pair(0, make_pair(i, i+k))); 
    }
    
    sort(el.begin(), el.end());
    memset(r, 0, sizeof(r));
    for(int i = 0; i < 100001; i++ ) p[i] = i; 
    int cost = 0; 

    for(pair<int, pair<int, int>> bruh : el){
        //printf("Looking at edge %d - %d with weight %d\n", bruh.second.first, bruh.second.second, bruh.first);
        if(!sameset(bruh.second.first, bruh.second.second)){
            cost += bruh.first; 
            merge(bruh.second.first, bruh.second.second);
        }
    }

    printf("%d", cost);
    return 0;
}