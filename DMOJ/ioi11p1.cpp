/*
ioi 11 p1
ray
wipwip
*/

//help

#include <cstdio>
#include <vector>

using namespace std; 

//no clue how to do these function questions.
int main(){
    int n; int m; int P;
    scanf("%d %d %d", &n, &m, &P); 
    int r[m][2];
    for(int i = 0; i < m; i++){
        scanf("%d %d", &r[i][0]); 
        scanf("%d %d", &r[i][1]);
    }
    int q; scanf("%d", &q);
    int g[q]; for(int i = 0; i < q; i++) scanf("%d", &g[i]);
    return 0;
}