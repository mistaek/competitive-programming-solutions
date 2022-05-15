#include <map>
#include <cstdio>

using namespace std; 
/* plan
take courses, set popularities 
use a loop to add up popularity scores 
fast enough?
*/
// misread question, proceed anyway :/ 

int main(){
    int students; 
    while(scanf(" %d", &students), students){
        map<int, int> popularity; 
        int cs[10000][5] = {}; 
        for(int i = 0; i < students; i++){
            //get popularities
            int ccode; 
            for(int j = 0; j < 5; j++){
                scanf(" %d", &ccode); 
                if(popularity.count(ccode) == 0) popularity[ccode] = 1; 
                else popularity[ccode]++;
                cs[i][j] = ccode;
            }    
        }
        //calc popularities. 
        int best = 0, count = 0; 
        for(int i = 0; i < students; i++){
            int pop = 0; 
            for(int j = 0; j < 5; j++){
                pop += popularity[cs[i][j]]; 
            }
            if(pop > best ){
                best = pop; 
                count = 1; 
            }
            else if(pop == best) count++;

        }
        printf("%d\n", count);

    }
    return 0; 
}