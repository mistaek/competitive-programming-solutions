/*
ccc08s1
ac - having some trouble running code with code runner..
*/

//simple?

#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std; 

int main(){
    pair<int, string> citypop[10001]; 
    int i= 0; 
    while(cin >> citypop[i].second >> citypop[i].first){
        i++;   
        if(citypop[i].second == "Waterloo") break;
    }
    sort(citypop, citypop + i);
    cout << citypop[0].second << "\n";

    return 0;
}