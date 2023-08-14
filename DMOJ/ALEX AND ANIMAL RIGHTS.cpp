/*
ALEXandANIMalRIGHTS
ray
AC
*/
//floodfill practice
#include <cstdio>
char m[40][55];
int ans = 0; 
//up down left right
int dirx[4] = {0, 0, -1, 1}; 
int diry[4] = {-1, 1, 0, 0};
bool monkey = false; 

void dfs(int i, int j){
    if(m[i][j] == '#') return; 
    if(m[i][j] == 'M') monkey = true; 
    
    m[i][j] = '#'; 
    for(int d = 0; d < 4; d++){
        dfs(i + dirx[d], j + diry[d]);
    }

}
int main(){
    int x, y; scanf("%d %d", &x, &y);
  
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            scanf(" %1c", &m[i][j]);
        }
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            
            if(m[i][j] != '#'){
                monkey = false; 
                dfs(i,j); 
                if(monkey) ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}