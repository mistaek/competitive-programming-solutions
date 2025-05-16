/*
1623A
WIP
*/

#include <cstdio>
#include <algorithm>
using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n, m, rb, cb, rd, cd; scanf("%d %d %d %d %d %d", &n, &m, &rb, &cb, &rd, &cd); 
        int xans = 1e9, yans = 1e9;
        if(rb <= rd){
            xans = rd - rb; 
        }
        else xans = n - rd + n - rb;
        if(cb <= cd) yans = cd - cb; 
        else yans = m - cd + m - cb; 

        printf("%d\n", min(xans, yans));
    }
    return 0;
}