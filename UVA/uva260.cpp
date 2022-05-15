/*
ray
uva 260
AC
*/

//hopefully easy?
#include <cstdio>

int m[205][205]; 
int n;
bool yes = false; 
int dirx[6] = {1, -1, 0, 0, 1, -1};
int diry[6] = {1, -1, 1, -1, 0, 0};

void dfs(int i, int j){
    if( i >= n || i < 0 || j < 0 || j >= n) return; 
    if(m[i][j] ==  0) return;
    if (j == n - 1){ 
        yes = true; 
        return; 
    }
    m[i][j] = 0;
    for(int d = 0; d < 6; d++){
        dfs(i +dirx[d], j +diry[d]);
    }
}



int main(){
    int c= 1; 
    while(scanf(" %d", &n), n != 0){
        char in; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf(" %1c", &in); 
                if(in == 'w') m[i][j] = 1; 
                else m[i][j] = 0;
            }
        }
        for(int i = 0; i < n; i++){
            dfs(i, 0); 
            if(yes) break; 
        }
        if(yes) printf("%d W\n", c); 
        else printf("%d B\n", c);
        yes = false; 
        c++;
    }

    return 0;
}