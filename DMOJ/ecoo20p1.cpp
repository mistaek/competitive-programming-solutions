/*
ecoo20p1
ray
AC
*/
#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std; 

string notes[4]; 
int val[4]; 

int subt(int a, int b){
    int ret = abs(a - b); //number of semitones apart 
    ret = min(ret, 12-ret);
    return ret; 
}
bool checkarr(){
    return ((subt(val[3],val[2]) == 3) && (subt(val[2] , val[1]) == 3) && (subt(val[1],val[0])  == 4)); 

}
void shiftarr(){
    int newarr[4]; 
    newarr[0] = val[3]; 
    newarr[1] = val[0]; 
    newarr[2] = val[1]; 
    newarr[3] = val[2]; 
    for(int i = 0; i < 4; i++) val[i] = newarr[i]; 
}
int main(){
    map<string, int> note; 
    note["C"] = 1; note["C#"] = 2; note["D"] = 3; note["D#"] = 4; note["E"] = 5; note["F"] = 6; note["F#"] = 7; note["G"] = 8; note["G#"] = 9; note["A"] = 10; note["A#"] = 11; note["B"] =  12; 
    int TC; scanf("%d", &TC);
    while(TC--){
        
        for(int i = 0; i < 4; i++){ cin >> notes[i]; val[i] = note[notes[i]];}
        if(checkarr()){
            printf("root\n");
        }       
        else{
            shiftarr(); 
            if(checkarr()){
                printf("first\n"); 
            }
            else{
                shiftarr();
                if(checkarr()){
                    printf("second\n"); 
                }
                else{
                    shiftarr(); 
                    if(checkarr()){
                        printf("third\n"); 
                    }
                    else printf("invalid\n");
                }
            }
        }
        
    }
    return 0;
}