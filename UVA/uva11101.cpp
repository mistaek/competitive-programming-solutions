/*
uva11101
ray
AC
*/

#include <cstdio>
#include <deque>

using namespace std; 
int main(){
    int p1; 
    int dirx[4] = {1, 0, -1, 0}, diry[4] = {0, 1, 0, -1};
    while(scanf("%d", &p1), p1){
        int grid[2001][2001] = {}; //avenue, street
        int vis[2001][2001] = {};
        for(int i = 0; i < 2001; i++) for(int j = 0; j < 2001; j++) grid[i][j] = -1; 
        deque<pair<int, int>> q; 

        for(int i = 0; i < p1; i++){
            int x, y; scanf("%d %d", &x, &y); grid[x][y] = 0;
            if(i == 0) q.push_back({x, y});
        }

        int p2; scanf("%d", &p2); 
        for(int i = 0; i < p2; i++){int x, y; scanf("%d %d", &x, &y); grid[x][y] = -2; }
        int ans = -1; 
        while(!q.empty()){
            int x = q.front().first, y = q.front().second; 
            q.pop_front();
            for(int i = 0; i < 4; i++){
                if(x + dirx[i] < 2001 && x + dirx[i] > -1 && y + diry[i] > -1 && y + diry[i] < 2001){
                    //printf("Visiting %d %d\n", x+dirx[i], y + diry[i]);
                    if(grid[x+dirx[i]][y + diry[i]] == -1){
                        grid[x + dirx[i]][y + diry[i]] = grid[x][y] + 1; 
                        q.push_back({x+ dirx[i],y+ diry[i]});
                    }
                    else if(grid[x+dirx[i]][y + diry[i]] == -2){
                        ans =  grid[x][y] + 1; 
                    }
                    else if(grid[x+dirx[i]][y + diry[i]] == 0 && vis[x+dirx[i]][y+diry[i]] == 0){
                        q.push_front({x + dirx[i],y + diry[i]});
                        vis[x+dirx[i]][y+diry[i]] = 1; 
                    }
                }
                //else printf("%d %d is out of bounds\n", x + dirx[i], y + diry[i]);
            }
            if(ans != -1) break; 

        }
        printf("%d\n", ans);

    }
    return 0;
}