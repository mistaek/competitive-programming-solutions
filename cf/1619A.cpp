/*
1619A
WIP
*/

#include <cstdio>
#include <string> 
#include <iostream>

using namespace std; 
int main(){
    int t; scanf("%d\n", &t);
    while(t--){
        string in; cin>>in; 
        if(in.length() % 2) printf("NO\n"); 
        else{
            bool trueeee = true; 
            for(int i = 0; i < in.length()/2; i++){
                if(in[i] != in[i + (in.length()/2)]) trueeee = false; 
            }
            if(trueeee) printf("YES\n"); 
            else printf("NO\n");
        }
    }
    return 0;
}