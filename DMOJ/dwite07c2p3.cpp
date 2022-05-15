/*
dwite for alex
ray
AC
*/

//dmoj user VinceLi is a blue coder

#include <cstdio>

char g[41][41];
int r, c; 
int out[6], dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
int room = 1; 


void dfs(int x, int y){
    if(x < 0 || y < 0 || y >= c || x >= r) return;
    if(g[x][y] == '#') return; 
    
    out[room]++;
    g[x][y] = '#';

    for(int i = 0; i < 4; i++){
        dfs(x+dirx[i], y + diry[i]);
    }


}
int main(){
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %1c", &g[i][j]);
            //printf("%c", g[i][j]);
        }
        //printf("\n");
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j<c; j++){
            if(g[i][j] != '.' && g[i][j] != '#'){
                room = g[i][j] - '0'; 
                dfs(i, j);
            }
        }
    }

    for(int i = 1; i <= 5; i++) printf("%d\n", out[i]);
    return 0;
}