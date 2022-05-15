/*
UVa 11157 Dynamic Frog
[NAME] 
WIP
*/

#include <cstdio>
#include <iostream>

#define max(a, b) ((a < b) ? b : a)

using namespace std; 

int n, d;

//not good 
int simul(pair<int, bool> rocks[]){
    
}

//workings
int main(){
    int TC; scanf("%d\n", &TC); 
    for(int c = 0; c < TC; c++){
    	scanf("%d %d", &n, &d); 
        pair<int, bool> rocks[n]; 
        for(int i = 0; i < n; i++){
            char t; int dist; 
            scanf(" %c-%d\n", &t, &dist);
            if(t == 'B') rocks[i] = make_pair(dist, false); 
            else rocks[i] = make_pair(dist, true);
        }
        printf("Case %d: %d\n", c+1, simul(rocks));
    }
    return 0; 
}