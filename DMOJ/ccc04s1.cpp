/*
ccc 04 s1 
ac - lengths too small
*/

#include <cstdio>
#include <string>
#include <iostream>

using namespace std; 

bool compare(string a, string b){
    if((int) a.length() < (int)b.length()) swap(a,b);
    bool s1 = true, s2 = true;
    for(int i = 0; i < (int)b.length(); i++){
        if(a[i] != b[i]) s1 = false; 
        if(a[(int)a.length() - (int)b.length() + i] != b[i]) s2 = false; 
    }
    return (s1 || s2); 
}

int main(){
    int n; scanf("%d", &n); 
    while(n--){
        string a, b, c; cin >> a >> b >> c; 
        if(compare(a, c) || compare(a, b) || compare(b, c)) printf("No\n");
        else printf("Yes\n");
    }

    return 0;
}