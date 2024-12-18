/*
992A
*/

#include <iostream>
#include <set>

using namespace std; 

int main(){ 
    int n; cin >> n; 
    set<int> cnt; 
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        if(a != 0)cnt.insert(a); 
    }

    cout << cnt.size() << "\n";
    return 0;
}