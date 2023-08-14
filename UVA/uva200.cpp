/*
uva 200
ray
AC
*/

#include <cstdio>
#include <string> 
#include <iostream>
#include <vector>
#include <queue>
#define min(a, b) ((a < b) ? a : b)
using namespace std; 

vector<char> out; 
vector<char> chars[28];
string ss[10000];
int v[28] = {};

void dfs(char c){
    int ind = c - 'A'; 
    v[ind] = 1;
    for(vector<char>::iterator it = chars[ind].begin(); it!= chars[ind].end(); it++){
        if(v[*it - 'A'] != 1) dfs(*it);
    } 
    out.push_back(c);
    //cout << "pushed " << c << " to out\n"; 
    
}
int main(){
        int i = 0; 
        while(getline(cin, ss[i]), ss[i][0] != '#') i++; 
        int j = 0;
        for(j = 1; j < i; j++){
        	//cout << "comparing " << ss[j-1]  << " and " << ss[j] <<"\n"; 
            for(int k = 0; k < min(ss[j].length(), ss[j-1].length()); k++){
                if(ss[j][k] != ss[j-1][k]){
                    chars[ss[j-1][k] - 'A'].push_back(ss[j][k]);
                    //cout << "pushed back " << ss[j][k] << " to " << ss[j-1][k] << "\n";
                    break;
                }
            }  
        } 
        dfs(ss[0][0]);
        
        for(vector<char>::reverse_iterator it = out.rbegin(); it!= out.rend(); it++){
            printf("%c", *it); 
        }
        printf("\n");
        
    
    return 0;
}