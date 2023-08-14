/*
1682C
AC with hint
*/

#include <cstdio>
#include <algorithm>
#include <map>

using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        map<int, int> occ; 
        int one = 0, two = 0; 
        for(int i =0; i < n; i++){
            int in; 
            scanf("%d", &in); 
            if(occ.count(in) == 0) occ[in] = 1; 
            else occ[in]++; 
            if(occ[in] == 1) one++; 
            if(occ[in] == 2){
                one--; two++;
            }
        }

        
        printf("%d\n", two + one/2 + one % 2);
    }
    return 0; 
}