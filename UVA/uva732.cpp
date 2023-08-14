#include <cstdio>
#include <stack>
#include <string> 
#include <iostream>
#include <algorithm>
#include <vector> 

// i push, o pop
//plan: sort to see if possible, then figure out how to compute orders
using namespace std; 
void process(string a, string b);
bool run(string a,string c, string b); 
string spaced(string a); 
int main(){
    string word1, word2; 
    while(cin >> word1 >> word2){
        string sorted1, sorted2; 
        sorted1 = word1; 
        sorted2 = word2; 
        sort(sorted1.begin(), sorted1.end()); 
        sort(sorted2.begin(), sorted2.end());
        if(sorted1 != sorted2){
            printf("[\n]\n"); 
            continue; 
        }
        process(word1, word2); 
        
    }
    return 0; 
}

void process(string a, string b){
    vector<string> out;
    //processing -- brute force
    string possibilities; 
    for(int i = 0; i < a.length(); i++){
        possibilities.push_back('i'); 
        possibilities.push_back('o'); 
    }
    sort(possibilities.begin(), possibilities.end()); 
    if(run(a, possibilities, b)) out.push_back(spaced(possibilities)); 
    while(next_permutation(possibilities.begin(), possibilities.end())){
        if(possibilities[0] == 'o') continue;
        if(run(a, possibilities, b)) out.push_back(spaced(possibilities));  
    }
    vector<string>::iterator it;
    printf("[\n");
    for(it = out.begin(); it!=out.end(); it++){
        cout << *it << "\n"; 
    }
    printf("]\n");
}
bool run(string a, string c, string b){
    string as = a; 
    string::iterator it; 
    stack<char> s; 
    for(it = c.begin(); it!=c.end(); it++){
        if(*it == 'i'){
            s.push(as[0]);
            as.erase(0,1); 
        } 
        else if(*it == 'o' && s.empty()) return false;
        else{
            as.push_back(s.top()); 
            s.pop(); 
        }
    }
    if(as == b) return true; 
    else return false;
}
string spaced(string a){
    string b; 
    for(int i = 0; i < 2*a.length(); i++){
        if(i%2) b.push_back(' '); 
        else b.push_back(a[i/2]);
    }
    b.pop_back(); 
    return b; 
}