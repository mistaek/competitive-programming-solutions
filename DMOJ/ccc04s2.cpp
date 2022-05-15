/*
ccc 04 s2
ac - simple problem but i am too busy listneing to kpop to pay attention
*/

#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std; 

int main(){
    int n, k; scanf("%d %d", &n, &k);
    pair<pair<int, int>, int> c[n] = {}, copy[n] = {};
    while(k--){
        for(int i = 0; i < n; i++){
            int s; scanf("%d", &s); 
            c[i].first.second = i; 
            c[i].first.first -= s; 
            copy[i] = c[i];
        }   
        sort(copy, copy+n);
        int rnk = 1;            
        c[copy[0].first.second].second = max(c[copy[0].first.second].second, rnk); 

        for(int i = 1; i < n; i++){
            if(copy[i].first.first != copy[i-1].first.first) rnk = i+1; 
            c[copy[i].first.second].second = max(c[copy[i].first.second].second, rnk); 
        }
    }
    printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n", copy[0].first.second + 1, -copy[0].first.first, copy[0].second);
    for(int i = 1 ; i< n; i++){
        if(copy[i].first.first != copy[0].first.first) break; 
        printf("Yodeller %d is the TopYodeller: score %d, worst rank %d\n", copy[i].first.second + 1, -copy[i].first.first, copy[i].second);

    }
    return 0;
}