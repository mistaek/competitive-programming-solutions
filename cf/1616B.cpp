/*
1616B
WIP
*/

#include <cstdio>
#include <map>
#include <string>

using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf(" %d", &n); 
        char str[n] = {}; 
        for(int i = 0; i < n; i++){ scanf(" %c", &str[i]); }
        int len = 1;
        bool t = false; 
        for(int i = 1; i < n; i++){
            if(str[i] < str[i-1]){
                len++; 
                t = true;
                //printf("t is now true\n");
            }
            else if(t && str[i] == str[i-1]) len++;
            else break;

        }
        for(int i = 0; i < len; i++){
            printf("%c", str[i]); 
        }
        for(int i = len-1; i >= 0; i--){
            printf("%c", str[i]);
        }
        printf("\n");
    }
    return 0;
}