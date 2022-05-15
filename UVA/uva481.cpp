/*
UVa 481
[NAME] 
AC
*/

#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std; 

int main(){
    int A[100000], idx = 0; 
    while(scanf("%d", &A[idx]) != EOF) idx++;
    int L[idx] = {}, L_id[idx] = {}, P[idx] ={};
    
    int lis = 0, lis_end = 0;
    for(int i = 0; i < idx; i++){
        int pos = lower_bound(L, L+lis, A[i]) - L;
        
        L[pos] = A[i]; 
        L_id[pos] = i; 
        P[i] = (pos) ? L_id[pos-1] : -1; 
        if(pos+1 >= lis){
            lis = pos+1; 
            lis_end = i; 
        }
    }  

    printf("%d\n-\n", lis);
    int x = lis_end; 
    stack<int> s; 
    for(; P[x] >= 0; x = P[x]){
        s.push(A[x]);
    }
    printf("%d\n", A[x]); 
    while(!s.empty()){
        printf("%d\n", s.top()); s.pop();
    }
    return 0;
}

