/*
ecoo2021p2
ac - site is gigaboomed
*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 
int main(){
    string dna; cin >> dna; 
    int arr[dna.length()] = {}; 
    for(int i = 0; i < dna.length(); i++){
        if(dna[i] == 'A') arr[i] = 1; 
        else arr[i] = 0;
    }
    int sw = -1; 
    for(int i = 0; i < dna.length(); i++){
        if(sw == -1){ printf("%c", dna[i]); sw = 1-arr[i];}
        else if(arr[i] == sw){
            sw = 1-sw; 
            printf("%c", dna[i]);
        }
        else{
            printf(" %c", dna[i]); 
            sw = 1- arr[i];
        }
    }
    return 0;
}