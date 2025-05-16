/*
CF1613B
AC - you are monke
*/

#include <cstdio>
#include <vector> 
#include <algorithm>
using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        int appears[1000001] = {};
        vector<int> seq; 
        for(int i = 0; i < n; i++){
            int in; scanf("%d", &in); 
            if(appears[in] == 0){ seq.push_back(in); appears[in] = 1;}
        }

        sort(seq.begin(), seq.end());
        int fp = 0; 
        for(int i = 1; i < n; i++){
            printf("%d %d\n", seq[i], seq[0]);
            fp++;
            if(fp == n/2) break;
        }
    }
    return 0;
}