/*
ccc 06 s1
ac - spent waay too much time until i found out i was using the wrong array name T_T
*/

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std; 
int p[2][256] = {}, possible[256] = {};
string ps[2];
int main(){

    for(int i = 0; i < 2; i++){
        cin >> ps[i]; 
        for(char a : ps[i]) p[i][a]++;
    }
    for(int i = 'A'; i < 'A' + 5; i++){
        possible[i] = max(p[0][i], p[1][i]);
        //printf("%c: %d\n", i, possible[i]);
    }
    for(int i = 'a'; i < 'a'+5; i++){
        possible[i] = min(p[0][i], p[1][i]);
        //printf("%c: %d\n", i, possible[i]);
    }

    int t; cin >> t; 
    while(t--){
        bool yes = true;
        string kid; cin >> kid;
        for(char a : kid)
            if(possible[a] == 0) yes = false; 

        if(yes) printf("Possible baby.\n");
        else printf("Not their baby!\n");
    }
    return 0;
}