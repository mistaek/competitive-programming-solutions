/*
ccc04 s3
ac : lol a-j is 10 letters
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std; 
string in[10][9]; int out[10][9] = {}; 

void parse(int i, int j){
    if(out[i][j] != -1) return; 

    if(in[i][j][0] - '0' < 10 && in[i][j][0] - '0' >= 0){
        int val = stoi(in[i][j]); 
        out[i][j] = val;
    }
    else{
        int val = 0;
        for(int l = 0; l < (int)in[i][j].length();l+=2 ){
            if(in[i][j][l] == '+'){ l--; continue;}//l-- for the plus 2
            int row = toupper(in[i][j][l]) - 'A'; int column = in[i][j][l+1] - '1';
            
            if(out[row][column] == -1){
                val = -1; 
                break; 
            }
            else val += out[row][column];
        }
        out[i][j] = val; 
    }
}

int main(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            cin >> in[i][j];
            //cout << in[i][j] << " "; 
            out[i][j] = -1;
        }
        //printf("\n");
    }
    for(int l = 0; l < 100; l++){
        for(int i = 0; i< 10; i++){
            for(int j = 0; j < 9; j++){
                parse(i,j);
            }
        }
    }
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 9; j++){
            if(j) printf(" "); 
            (out[i][j] == -1) ? printf("*") : printf("%d", out[i][j]); 
        }
        printf("\n");
    }
    return 0;
}
