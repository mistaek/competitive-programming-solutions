/*
1618B
AC
*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 

int main(){
    int t; scanf("%d\n", &t); 
    while(t--){
        int n; scanf("%d\n", &n); 
        char bigrams[n][2];
        for(int i = 0; i < n-2; i++){
            scanf(" %c%c", &bigrams[i][0], &bigrams[i][1]);
        }
        string output = ""; 
        output += bigrams[0][0];
        output += bigrams[0][1];
        bool truee = true; 
        for(int i = 1; i < n-2; i++){
            if(output[output.length() -1] != bigrams[i][0]){
                truee = false; 
                output += bigrams[i][0];
                output += bigrams[i][1];  
            }
            else output += bigrams[i][1];
        }
        if(truee) output += "a";
        cout << output << "\n";
    }
    return 0;
}