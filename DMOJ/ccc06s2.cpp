/*
ccc 06 s2 
wip
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std; 

int main(){
    map<char, char> decoder; 
    string one, two, three; 
    getline(cin, one); getline(cin, two); getline(cin, three);
    for(int i = 0; i < (int)one.length(); i++){
        decoder[two[i]] = one[i];
    }
    for(int i = 0; i < (int) three.length(); i++){
        if(decoder.count(three[i])) printf("%c", decoder[three[i]]);
        else printf(".");
    }
    return 0;
}   