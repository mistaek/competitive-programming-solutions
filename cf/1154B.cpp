/*
1154B
*/

#include <iostream>
#include <set>
#include <functional>
using namespace std; 

int main(){
    int n; cin >> n; 
    set<int> values;
    for(int i = 0; i < n; ++i){
        int a; cin >> a; values.insert(a); 
    }

    
    function<int()> pop = [&]{
        int v = *values.begin(); 
        values.erase(values.begin()); 
        return v; 
    };

    if(values.size() >= 4){
        cout << "-1\n"; 
    }
    else if(values.size() == 3){
        int a = pop(), b = pop(), c = pop(); 
        if(b - a == c - b) cout << b-a <<"\n";
        else cout << "-1\n"; 
    }
    else if(values.size() == 2){
        int a = pop(), b = pop(); 
        if((b-a) % 2 == 0){
            cout << (b-a)/2 << "\n"; 
        }
        else cout << b-a << "\n";
    }
    else cout << 0 << "\n";
    return 0;
}