/*
UVa 11831
[NAME]
AC
*/

#include <cstdio>
 
 //up (0, 1) down (0, -1) left(-1, 0) right(1, 0)
//ahh, row form messed me up
int dirx[4] = {-1, 0, 1, 0};
int diry[4] = {0, 1, 0, -1};

//almost done
int main(){
    int n, m, s; 
    while(scanf(" %d %d %d", &n, &m, &s), n){
        char grid[102][102];
        int bx, by, dir; 
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf(" %1c",&grid[i][j]);
                if(grid[i][j] == 'N'){ dir = 0; bx = i; by = j; } 
                else if(grid[i][j] == 'S') {dir = 2; bx = i; by = j; } 
                else if(grid[i][j] == 'L') {dir = 1; bx = i; by = j;} 
                else if(grid[i][j] == 'O') {bx = i; by = j; dir = 3; } 
            } 
        }
        //traversal
        
        int ans = 0;
        //FDFFFFFFEEFFFFFFEFDF
        
        for(int i = 0; i < s; i++){
            char cmd; scanf(" %1c", &cmd);
            if(cmd == 'D'){dir++; if(dir == 4) dir = 0; }  
            else if(cmd == 'E'){dir--; if(dir == -1) dir= 3;   }
            else if(cmd == 'F'){
            	
                int nx = bx + dirx[dir]; 
                int ny = by + diry[dir];
                //printf("%d %d, considering %d %d which is %c\n", bx, by, nx, ny, grid[nx][ny]);
                if(nx == 0 || nx == n+1 || ny == 0 || ny == m+1) continue; 
                if(grid[nx][ny] == '#') continue; 
                if(grid[nx][ny] == '*') { ans++; grid[nx][ny] = '.';} //tricky!
                bx = nx; by = ny;
            }
            
            
        }
        
        printf("%d\n", ans);
        
    }
    return 0; 
}