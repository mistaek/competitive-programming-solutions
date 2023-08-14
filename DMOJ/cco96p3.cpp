/*
cco96p3
ac
*/

#include <cstdio>
#include <cstring> 
int grid[32][32] = {};

void process(int x1, int x2, int y1, int y2){
    char cmd; scanf(" %1c", &cmd); 
    if(cmd == 'f'){
        //printf("set %d %d %d %d to 1\n", x1, x2, y1, y2);
        for(int i = x1; i < x2; i++){
            for(int j = y1; j< y2; j++) grid[i][j] = 1; 
        }
    }
    if(cmd == 'p'){
        int range = x2-x1; 
        process(x1 + (range/2), x1 + range, y1, y1+ (range/2)); 
        process(x1, x1 + (range/2), y1, y1 + (range/2)); 
        process(x1, x1+ (range/2), y1 + (range/2), y1 + range);
        process(x1 + (range/2), x1 + range, y1 + (range/2), y1 + range);
    }
} 
int main(){
    int tc; scanf("%d", &tc);
    while(tc--){
        for(int i =0; i < 32; i++) for(int j = 0; j < 32; j++) grid[i][j] = 0;
        process(0, 32, 0, 32);
        int ans =0;         
        process(0, 32, 0, 32);
        for(int i = 0; i < 32; i++){
            for(int j = 0; j < 32; j++){
                ans += grid[i][j];
            }
        }
        
        printf("There are %d black pixels.\n", ans);
    }
    return 0;
}