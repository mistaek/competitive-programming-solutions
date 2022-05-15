/*
uva 872
ray
AC
*/

//going through a tutorial for this one
#include <cstdio> 
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <sstream>

using namespace std; 

int mtx[26][26];
bool used[26]; int slength;
bool ansed; 
char ans[26];
string in; string ltrs; 

//generate correct answers
void dfs(int idx){
    if(idx == slength){
        //if the index has reached the end
        ansed = true;
        //an answer exists 
        //output the said answer
        for(int i = 0; i < slength; i++){
            if(i) printf(" %c", ans[i]);
            else printf("%c", ans[i]);
        }
        printf("\n");
        return; 
    }
    int i, j; 
    
    for(i = 0; i < slength; i++){
        //take a letter, in this case s[i]
        if(!used[i]){ //if it hasn't been used in ans already
            for(j = 0; j < idx; j++){
                //if the j letter has been used, and it is greater than i, can't use in the string
                if(mtx[ltrs[i] - 'A'][ans[j] - 'A']) break; 
                
            }
            if(j == idx){ //if no contradiction exists
                ans[idx] = ltrs[i];
                used[i] = true; //use the letter
                dfs(idx+1);//generate the rest of the answer
                used[i] = false;  //return to unused 
            }
        }
    }
    

}
int main(){
    int TC; scanf("%d\n", &TC); 
    while(TC--){
        scanf("\n"); //pesky newline

        stringstream ss; 
        getline(cin, in); 

        //morris's append letters
        ss << in; 
        ltrs = ""; 
        while(ss >> in) ltrs+=in;

        sort(ltrs.begin(), ltrs.end()); //allows alphabetical order output

        memset(mtx, 0, sizeof(mtx));
        ss.clear();

        getline(cin, in); //get constraints
        ss << in;
        while(ss >> in) mtx[in[0] - 'A'][in[2] - 'A'] = 1; 

        ansed = false; 
        slength = ltrs.length();
        dfs(0);
        if(!ansed) printf("NO\n");
        if(TC) printf("\n");
    }
    return 0; 
}