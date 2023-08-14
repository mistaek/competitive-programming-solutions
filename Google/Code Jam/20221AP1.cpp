/*
2022 1A P1
WIP
*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std; 
int main(){
    int tc; scanf("%d\n", &tc);
    for(int TC = 1; TC <= tc; TC++){
        printf("Case #%d: ", TC); 
        string s; cin >> s; 
        int ctr = 1;
        for(int i = 0; i < s.length(); i++){
            printf("%c", s[i]); 
            if(i < s.length() - 1 && s[i] == s[i+1]) ctr++;
            else if(i < s.length() - 1 && s[i] < s[i+1]){ 
                for(int j = 0; j < ctr; j++)   printf("%c", s[i]); 
            }
            else{
                ctr = 1;
            }

        }
        printf("\n");
    }
    return 0;
}