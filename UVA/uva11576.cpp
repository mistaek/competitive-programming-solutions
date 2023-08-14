/*
uva 11576 
ac
*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 
int b[101], k, w; 
string l, c; 
void prep(){
    int i = 0, j = -1; b[0] = -1; 
    while(i < k){
        while(j >= 0 && c[i]!= c[j])j = b[j]; 
        i++; j++;
        b[i] = j; 
    } 
}
int kmp(){
    int i = 0, j =0; 
    while(i < k){
        while(j >= 0 && c[j] != l[i]) j=b[j]; 
        i++; j++; 
    }
    return j;
}
int main(){
    int tc; scanf("%d", &tc); 
    while(tc--){
        int ans = 0; 
        scanf("%d %d", &k, &w);
        cin >> c; ans += k;
        for(int i = 1; i < w; i++){
            l = c; 
            cin >> c; 
            //cout << l << "\n" << c << "\n";
            prep(); 
            //printf("%d\n", kmp());
            ans += k - kmp(); 
        }
        printf("%d\n", ans);
    }
    return 0;
}