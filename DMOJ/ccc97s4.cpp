/*
CCC 97 S4
[NAME]
WIP
*/

#include <cstdio>
#include <map>
#include <string> 
#include <iostream>
using namespace std; 

int main(){
    //using getline cause i m bad 
    //not working just yet.
    int TC; 
    scanf("%d\n", &TC); 
    while(TC--){  
        int num = 1; 
        string line; 
        map<string, int> dictionary; 
        while(getline(cin, line)){
        	cout << line<< "\n"; 
        	
            string word; 
            
            for(int i = 0; i < (int)line.length(); i++){
                if(line[i] != ' ' && line[i] != '\n') word.push_back(line[i]); 
                else{
                    if(dictionary[word] == 0) {
                    	cout << word << line[i];
                    	dictionary[word] = num;
                    	num++;
                    } 
                    else{ cout << dictionary[word] << line[i]; }
                    word.clear();

                }
            }
            

        }

    }
    return 0;
}