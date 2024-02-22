/*
w24 d
*/

#include <iostream>
#include <string>

using namespace std; 

int n, idx = 0; 
string s; 

long long parse(){
    if(idx == n) return 1; 
    if(s[idx] == ')'){
        idx++; 
        return 0;
    }
    if(s[idx] == '('){
        idx++;
        long long expr = parse();
       
        ++expr; 
        if(idx == n) return expr; 
        if(s[idx] == '(') return expr * parse(); 
        else{
            idx++;
            return expr; 
        }
    }
}
int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0); 

    cin >> n >> s;
    cout << parse() << "\n"; 


    return 0;
}
