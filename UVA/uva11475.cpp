/*
uva 11475
ac
*/

#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std; 
string line, rev; int b[100001]; 

void prep(){
    int i = 0, j = -1; b[0] = -1; 
    while(i < (int)rev.size()){
        while(j >= 0 && rev[j] != rev[i]) j = b[j];
        i++; j++; 
        b[i] = j; 
    }
}
int kmp(){
    prep(); 
    int i = 0, j = 0; 
    while(i < (int) line.size()){
        while(j >= 0 && line[i] != rev[j]) j = b[j];
        i++; j++; 
    }
    return j;
}
int main(){
    while(getline(cin, line)){
        rev = line; 
        reverse(rev.begin(), rev.end()); 
        int f = kmp();
        for(int i = 0; i < ((int)line.size()) - f; i++){
            printf("%c", line[i]); 
        }
        cout << rev; 
        printf("\n");
    }
    return 0;
}