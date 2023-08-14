/*
ecooooooo r2 p1
ray 
wip (wipwip, so to speak)
*/

//if anybody has a good vscode theme pls tell me my editor is uglyy
#include <cstdio>
#include <iostream>
#include <string>

using namespace std; 

//naive brute force -- much too slow 
int main(){
    int TC =10; 
    while(TC--){
        string s; getline(cin, s); 
        int l = s.length();
        bool yes = false; 
        int i;
        for(i = l; i > 1; i--){
        	//printf("LOOKING FOR PALINDROMES OF LENGTH %d\n", i); 
            for(int j = 0; j < l - i +1; j++){
            	//printf("STARTING AT INDEX %d\n", j);
                yes = true; 
                for(int k = j; k <= (j + i)/2; k++){
                    if(s[k] != s[i + j - 1-(k-j)]){
                    	//printf("%c is not %c, ind %d %d\n", s[k], s[i + j - 1-(k-j)], k, i + j - 1-(k-j)); 
                        yes = false; 
                        break; 
                    }
                }
                if(yes) break; 
            }
            if(yes) break; 
        }
        printf("%d\n", l - i);

    }
    return 0;
}
