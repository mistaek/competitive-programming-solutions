/*
1582C
WIP
*/

#include <cstdio>
#include <algorithm>

using namespace std; 
int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 
        char str[n]; 
        for(int i = 0; i < n; i++){
            scanf(" %1c", &str[i]);
        }
        int ans = -1; 
        for(int i = 0; i < 26; i++){
            int it1 = 0, it2 = n-1, tans = 0; 
            while(it1 < it2){
                if(str[it1] == str[it2]){
                    it1++; it2--;
                }
                else if(str[it1] == 'a' + i){
                    tans++;
                    it1++;
                }
                else if(str[it2] == 'a' + i){
                    tans++; 
                    it2--;
                }
                else{
                    tans = -1; 
                    break;
                } 
            }
            if(tans == -1) continue; 
            else if(ans == -1) ans = tans; 
            else ans = min(ans, tans);
        }
        printf("%d\n", ans);
    }
    return 0;
}