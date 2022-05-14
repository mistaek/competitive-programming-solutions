/*
1616A
WIP
*/

#include <cstdio>
#include <map>

using namespace std; 

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n);
        map<int, int> m;
        int ans = 0; 
        for(int i = 0; i < n; i++){
            int in; scanf("%d", &in);
            if(m.find(in) == m.end()){
                ans++; 
                m[in] = 1; 
            }
            else if(m.find(-in) == m.end()){
                ans++; 
                m[-in] = 1; 
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}