/*
BOARD GAMES
[NAME]
AC
*/

#include <cstdio>
#include <queue>

#define min(a, b) ((a < b) ? a : b)
using namespace std; 

bool visited[10000005];

int steps[10000005] = {}; 

int main(){
    //dev says bfs
    int n, m; //n go to m
    scanf("%d %d", &n, &m);  
    queue<int> s;
    s.push(n);
    steps[n] = -1; 
    while(!s.empty() && !visited[m]){
        int p = s.front(); 
        steps[p]++;
        s.pop(); 
        if(!visited[p]){
            if(3*p <= 10000000){
                if(!visited[3*p]){ s.push(3*p); steps[3*p] = (steps[3*p] != 0) ? min(steps[3*p], steps[p]) : steps[p];} 
            }
            if(p-1 >0 ){  
                if(!visited[p-1]){ s.push(p-1); steps[p-1] = (steps[p-1] != 0) ? min(steps[p-1], steps[p]) : steps[p]; }
            }
            if(p-3 > 0){
                if(!visited[p-3]){ s.push(p-3); steps[p-3] = (steps[p-3] != 0) ? min(steps[p-3], steps[p]) : steps[p];}
            }
            if(p%2 == 0){
                if(!visited[p/2]) { s.push(p/2); steps[p/2] = (steps[p/2] != 0 ) ? min(steps[p/2], steps[p]) : steps[p]; }
            }
        }
        visited[p] = true; 
        

    }
    printf("%d", steps[m]);

    return 0; 
}