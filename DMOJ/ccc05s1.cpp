/*
ccc05s1
ac
*/

//ltierally the worst problem ever invented
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std; 
int main(){
    map<char, int> dict; dict['A'] = 2; dict['B'] = 2; dict['C'] = 2; dict['D'] = 3; dict['E'] = 3; dict['F'] = 3; dict['G'] = 4; dict['H'] = 4; dict['I'] = 4; dict['J'] = 5; dict['K'] = 5; dict['L'] = 5; dict['M'] = 6; dict['N'] = 6; dict['O'] = 6; dict['P'] = 7; dict['Q'] = 7; dict['R'] = 7; dict['S'] = 7; dict['T'] = 8; dict['U'] = 8; dict['V'] = 8; dict['W'] = 9; dict['X'] = 9; dict['Y'] = 9; dict['Z'] = 9; 
    int n; scanf("%d\n", &n); 
    while(n--){
        string line; cin >> line;
        vector<int> num; 
        for(char a : line){
            if(a == '-') continue; 
            if(a - '0' >=0 && a-'0' <10) num.push_back(a-'0'); 
            else num.push_back(dict[a]);
        }
        printf("%d%d%d-%d%d%d-%d%d%d%d\n", num[0], num[1], num[2], num[3], num[4], num[5], num[6], num[7], num[8], num[9]);
    }
    return 0;
}