/*
ccc08s4
wip
*/

//not so simple?   

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 0;
int t, hand[4];

int operate(int op, int num1, int num2){//dumb block of code
    if(op ==0 ) return num1+num2; 
    if(op ==1) return num1-num2;
    if(op == 2) return num1*num2; 
    if(op == 3) {
        int a = num1/num2; 
        if(a * num2 != num1) return 1e9;
        else return num1/num2; 
    }
    return 0;
}
void calc(){
    int ret[3];
    for(int i = 0; i < 4; i++){
        ret[0] = operate(i, hand[0], hand[1]);
        if(ret[0] == 1e9) continue; 
        for(int j = 0; j < 4; j++){
            ret[1] = operate(j, ret[0], hand[2]); 
            if(ret[1] == 1e9) continue; 
            for(int k = 0; k < 4; k++){
                ret[2] = operate(k, ret[1], hand[3]);
                if(ret[2] == 1e9) continue;
                if(ret[2] <=24) ans = max(ans, ret[2]);
            }
        }
    }
}
int main(){
    scanf("%d", &t); 
    while(t--){
        ans = -1e9;
        for(int i = 0; i <4; i++) scanf("%d", &hand[i]);
        sort(hand, hand+4);
        do{
            calc();
        }while(next_permutation(hand, hand+4));
        printf("%d\n", ans);
    }
    return 0;
}