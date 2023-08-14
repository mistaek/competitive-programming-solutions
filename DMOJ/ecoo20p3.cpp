/*
ecoo20p3
ray
wip
*/

#include <cstdio>
#include <iostream>

using namespace std; 
int xbound, ybound;

char number[505][505];
int dirx[4] = {1, -1, 0, 0}; 
int diry[4] = {0, 0, 1, -1};
void dfs(int x, int y){

    if(x < 0 || x >= ybound || y < 0 || y >= xbound) return; 
    if(number[x][y] == '*' || number[x][y] == 'v') return; 
    number[x][y] = 'v';
    for(int i = 0; i < 4; i++){
        dfs(x+dirx[i], y +diry[i]);
    } 
}
int main(){
    int TC; scanf("%d", &TC); 
    while(TC--){
        int n; scanf("%d", &n); 
        while(n--){
            int h, w; scanf("%d %d", &h, &w); 
            char grid[h][w]; 
            int top=1000, bot = -1, right = -1, left = 1000; 
            for(int i = 0; i < h; i++){
                for(int j = 0; j < w; j++){
                    scanf(" %1c", &grid[i][j]);
                    if(grid[i][j] == '*'){
                        top = min(top, i); 
                        bot = max(bot, i); 
                        right = max(right, j); 
                        left = min(left, j);
                    }
                }
            }
            
            int roomcount = 0; 
            xbound = right-left +1; 
            ybound = bot - top +1; 
            for(int i = 0; i < bot-top+1; i++){
                for(int j = 0; j < right-left+1; j++){
                    number[i][j] = grid[i+top][j+left];
                }
            }
            
            for(int i = 0; i < ybound; i++){
                for(int j = 0; j < xbound; j++){
                    if(number[i][j] != '*' && number[i][j] != 'v'){
                        dfs(i,j); 
                        roomcount++;
                    }
                }
            }
            /*
            for(int i = 0; i < ybound; i++){
                for(int j = 0; j < xbound; j++){
                    printf("%c", number[i][j]);
                }
                printf("\n");
            }
            */
            

            //printf("roomcount: %d\n",roomcount); 
            if(roomcount == 1) printf("1"); 
            else if(roomcount == 2){
                if(number[0][xbound-1] == '*') printf("4");
                else printf("7");
            }
            else if(roomcount == 3){
                if(number[1][0] == '*') printf("5"); 
                else printf("2"); 
            }
            else if(roomcount == 4){
                printf("3");                
            }
            else if(roomcount == 5){
                if(number[1][xbound-1] == '*'){
                    if(number[ybound-2][0] == '*') printf("0");
                    else printf("9"); 
                } 
                else printf("6");
            }
            else if(roomcount == 7) printf("8");
            
        }
        
        printf("\n");
    }
    return 0;
}