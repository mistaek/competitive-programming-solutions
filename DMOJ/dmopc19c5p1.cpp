/*
dmopc 2019 contest 5???? bruh p1
ray 
wip 
*/

#include <cstdio>
#include <set> 
#include <string>
#include <iostream> 
using namespace std; 

set<string> obj; 

int main(){
    int m, n;
    scanf("%d %d\n", &m, &n); 
    for(int i = 0; i < m; i ++){
        string haves; 
        getline(cin, haves); 
        obj.insert(haves); 
    }
    int ans = 0; 
    for(int i = 0; i < n; i++){
        bool good = true; 
        int t; scanf("%d\n", &t); 
        for(int j = 0; j < t; j++){
        string need; getline(cin, need); 
        if(obj.count(need) == 0) good = false; 
        }
        if(good) ans++; 
    }
    printf("%d", ans);
    return 0; 
}