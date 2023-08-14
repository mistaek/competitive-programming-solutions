#include <cstdio>
#include <map>
#include <string>
// isnt this person a little evil
//greedy algorithm? 
//using deque with string

using namespace std; 
int num = 0; 

void process(string stk, int f[]){
    if(f[1] > f[2]) num++; 
    if(stk.length() == 0) return;
    if(f[1] == 0) return; 

    int front[3];
    int back[3]; 
    for(int i = 0; i < 3; i++){
    	front[i] = f[i]; 
    	back[i] = f[i];
    }
    //pop front
    if(stk[0] == '1') front[1]--; 
    else front[2]--; 
    process(stk.substr(1), front);
    //pop back
    if(stk[stk.length()-1] == '1') front[1]--; 
    else front[2]--; 
    process(stk.substr(0, stk.length()-1), back);
}

int main(){
    int n; 
    map<char, int> freq; 
    freq['1'] = 0; freq['2'] = 0; 
    scanf("%d", &n); 
    string s; 
    while(n--){
        char in; 
        scanf(" %c", &in); 
        s.push_back(in); 
        freq[in]++; 
    }
    int f[3] = {0, freq['1'], freq['2']};
    process(s, f); 
    printf("%d", num);
    return 0; 
}