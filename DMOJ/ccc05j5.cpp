/*
ccc05j5
ac kekw
*/
//just forloop!
#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 

int main(){
    string word; 
    while(cin >> word){
        if(word == "X") break;
        bool yes = true; int bopen = 0; 
        for(int i = 0; i < word.length(); i++){
            if(i == word.length()-1){
                if(word[i] == 'S'){
                    bopen--; 
                    if(bopen){ yes = false; }
                }
                else if(word[i] == 'A'){
                    if(bopen) yes = false; 
                }
                else yes = false; 

            }
            else{
                if(word[i] == 'A'){
                    if(word[i+1] != 'N' && word[i+1] != 'S'){ 
                        yes = false; 
                    }
                    else if(word[i+1] == 'S' && bopen < 1){yes = false;}
                    
                }
                else if(word[i] == 'B'){
                    bopen++;
                    if(word[i+1] == 'A'){
                        continue; 
                    }
                    else if(word[i+1] == 'B'){
                        continue;
                    }
                    else yes = false; 
                }
                else if(word[i] == 'N'){
                    if(word[i+1] != 'A' && word[i+1] != 'B') yes = false; 
                }
                else if(word[i] == 'S'){
                    bopen--; 
                    if(bopen < 0) yes = false; 
                    if(word[i+1] != 'N' && word[i+1] != 'S') yes = false; 
                }
                else yes = false; 
            }
            //printf("bopen is %d\n", bopen); 
            //if(yes == false) printf("wrong at index %d\n", i); 
        }
        if(yes) printf("YES\n"); 
        else printf("NO\n");
    }    
    return 0;
}