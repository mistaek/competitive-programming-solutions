/*
1153C
AC
*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std; 

int main(){
    int n; 
    cin >> n; 
    auto impossible = []{
        cout << ":(\n"; exit(0); 
    };
    if(n % 2){
        impossible();
    }

    char s[n+1] = {}; 
    s[n] = '\0';
    bool matched[n] = {};
    stack<int> opens; 
    for(int i = 0; i < n; ++i){
        cin >> s[i]; 
        if(i == 0){
            if(s[i] == ')'){
                impossible();
            }
            s[i] = '(';
        }
        else if(i == n-1){
            if(s[i] == '('){
                impossible();
            }
            s[i] = ')'; 
        }
        else{
            if(s[i] == '('){
                opens.push(i); 
            }
            else if(s[i] == ')'){
                if(!opens.empty()){
                    matched[opens.top()] = matched[i] = 1; 
                    opens.pop(); 
                }   
            }
        }
    }


    int bal = opens.size();
    for(int i = n-2; i >= 1; --i){
        if(s[i] == '('){
            if(!matched[i]) impossible(); 
        }
        else if(s[i] == ')'){
            if(!matched[i]) bal--; 
        }
        else{
            if(bal >= 0){
                if(!opens.empty()){
                    matched[opens.top()] = 1; 
                    opens.pop();
                }
                s[i] = ')';
                --bal; 
            }
            else{
                s[i] = '('; ++bal; 
            }
        }
    }


    if(bal != 0) impossible(); 
    
    cout << s << "\n"; 


    return 0;
}