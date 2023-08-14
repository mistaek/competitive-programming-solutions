/*
UVa 11831
[NAME]
WIP
*/ 

#include <cstdio> 

int main(){
    //base input/loop
    int n, m, s; 
    while(scanf("%d %d %d", &n, &m, &s), n){
        //graph input
        char field[2+n][2+m];
        int x, y, dirx, diry;  
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                scanf(" %1c", &field[i][j]); 
                if(field[i][j] == 'N'){
                    dirx = 0; diry = -1; 
                    x = i; y = j;
                }
                else if(field[i][j] == 'S'){
                    dirx = 0; diry = 1; 
                    x = i; y = j;
                }
                else if(field[i][j] == 'L'){
                    dirx = 1; diry = 0; 
                    x = i; y = j;
                }
                else if(field[i][j] == 'O'){
                    dirx = -1; diry = 0; 
                    x = i; y = j;
                }
                printf("%c", field[i][j]);
            }
            printf("\n");
        }

        //direction processing.
    }
    return 0;
}