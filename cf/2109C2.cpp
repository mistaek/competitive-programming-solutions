/*
2109A
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
#include <map> 
#include <functional>

using namespace std; 

int main(){
    
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; int resp; 
        cout << "mul 9" << endl; 
        cin >> resp; 
        cout << "digit" << endl; 
        cin >> resp; 
        cout << "digit " << endl; 
        cin >> resp; 
        if(n  == 9) cout << "!" << endl; 
        else{
            cout << "add " << n - 9 <<endl; 
            cin >> resp; 
            cout << "!" << endl; 
        }
        cin >> resp; 
        //current max: 81
    }
    return 0;
}