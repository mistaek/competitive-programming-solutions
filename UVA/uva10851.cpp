/*
uva 10851
ac
*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 
int main(){
    int tc; scanf("%d\n", &tc); 
    while(tc--){
        string line; 
        int m = 0;
        int grid[10][80];
        for(int i = 0; i < 10; i++){
            getline(cin, line); 
            m = (int)line.length(); 
            for(int j = 0; j < m; j++){
                grid[i][j] = (line[j] == '\\'); 
            }
        }
        int message[m-2] = {};
        for(int i = 1; i < 9; i++){
            for(int j = 1; j < m-1; j++){
                message[j-1] |= (grid[i][j] << i-1);
            }
        }
        for(int i = 0; i < m-2; i++) printf("%c", (char)message[i] );
        printf("\n");
        scanf("\n"); 
    }
    return 0;
}