/*
ccc21j2
AC
*/

#include <iostream>
#include <string>

using namespace std; 

int main(){
    int max = 0, cur; string name, win; 
    int n; cin >> n;
    while(n--){
        cin >> name >> cur; 
        if(cur > max){ win = name; max = cur;} 
    }
    cout << win;
    return 0;
}