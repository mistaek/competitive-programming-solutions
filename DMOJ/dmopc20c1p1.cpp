/*
dmopc20c1 p1
wip
*/

#include <cstdio>
#include <iostream>
#include <string>

using namespace std; 

int main(){
    int n; scanf("%d\n", &n);
    for(int i =0; i < n; i++){
        bool c=false, m = false;
        string quiz; cin>>quiz; 
        for(char subj : quiz){
            if(subj == 'C') c = true; 
            if(subj == 'M') m = true; 
        }

        if(c && m) printf("NEGATIVE MARKS\n"); 
        else if(c || m) printf("FAIL\n");
        else printf("PASS\n");
    }
    return 0;
}