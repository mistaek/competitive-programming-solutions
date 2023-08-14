/*
1607A
WIP
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std; 
int main(){
    int t; 
    cin >> t; 
    while(t--){
        string kb, str; cin>>kb>>str;
        map<char, int> pos; 
        for(int i = 1; i <= 26; i++){
            pos[kb[i-1]] = i;
        }
        int ans = 0; 
        for(int i = 1; i < str.length(); i++){
            ans += abs(pos[str[i]] - pos[str[i-1]]);
        }
        printf("%d\n", ans); 
    }

    return 0;
}