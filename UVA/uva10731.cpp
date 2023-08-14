/*
uva 10731 test : scc practice
ray
wipwip
*/

#include <cstdio>
#include <vector>
#include <stack>
#include <map> 
using namespace std; 
//tbh i'd rather not
//not doing this one
int main(){
    int n; 
    while(scanf("%d", &n)){
        char arr[5];
        for(int i = 0; i < 5; i++){
            scanf(" %c", &arr[i]);
        }
        char a; scanf(" %c", &a);
        vector<int> adjl[1000];
        for(int i = 0; i < 5; i++){
            adjl[a-'a'].push_back(arr[i] - 'a');
        }


    }
    return 0;
}