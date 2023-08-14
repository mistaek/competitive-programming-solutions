/*
1609B
ac
*/

#include <cstdio>


int main(){
    int n, q; scanf(" %d %d", &n, &q); 
    char str[n]; 
    for(int i = 0; i < n; i++){
        scanf(" %c", &str[i]); 
    }
    int ans = 0; 
    for(int i = 0; i < n-2; i++){
        if(str[i] == 'a' && str[i+1] == 'b' && str[i+2] == 'c') ans++;
    }
    while(q--){
        int ind; char newc; 
        scanf(" %d %c", &ind, &newc); 
        ind--;
        if(str[ind] == 'a'){
            if(ind + 2 <n){
                if(str[ind + 1] == 'b' && str[ind+2] == 'c') ans--;
            }
        }
        if (str[ind] == 'b'){
            if(ind + 1 < n && ind-1 >= 0){
                if(str[ind-1] == 'a' && str[ind + 1] == 'c') ans--;
            }
        }
        if(str[ind] == 'c'){
            if(ind - 2 >= 0){
                if(str[ind -1] == 'b' && str[ind-2] == 'a') ans--; 
            }
        }
        str[ind] = newc; 
        if(str[ind] == 'a'){
            if(ind + 2 <n){
                if(str[ind + 1] == 'b' && str[ind+2] == 'c') ans++;
            }
        }
        if (str[ind] == 'b'){
            if(ind + 1 < n && ind-1 >= 0){
                if(str[ind-1] == 'a' && str[ind + 1] == 'c') ans++;
            }
        }
        if(str[ind] == 'c'){
            if(ind - 2 >= 0){
                if(str[ind -1] == 'b' && str[ind-2] == 'a') ans++; 
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}