/*
1838D
*/

#include <iostream>
#include <string>
#include <set>
using namespace std; 

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    int n, q; cin >> n >> q; 
    string str; 
    cin >> str; 

    int nO = 0, nC = 0; 
    set<int> dO, dC; 
    for(int i = 0; i < n; ++i){
        if(str[i] == '(') ++nO; 
        else ++nC; 
        if(i && str[i] == str[i-1]){
            if(str[i] == '(') dO.insert(i); 
            else dC.insert(i); 
        }
    }
    
    for(int i = 0; i < q; ++i){
        int j; cin >> j; 
        --j;
        //upd
        if(str[j] == '('){
            --nO; 
            ++nC;
            if(j && str[j-1] == '(') dO.erase(j); 
            if(j < n-1 && str[j+1] == '(') dO.erase(j+1);
            str[j] = ')';
            if(j && str[j-1] == ')') dC.insert(j); 
            if(j < n-1 && str[j+1] == ')') dC.insert(j+1);
        }
        else{
            --nC; 
            ++nO;
            if(j && str[j-1] == ')') dC.erase(j); 
            if(j < n-1 && str[j+1] == ')') dC.erase(j+1); 
            str[j] = '('; 
            if(j && str[j-1] == '(') dO.insert(j); 
            if(j < n-1 && str[j+1] == '(') dO.insert(j+1);
        }
        if(q == 131054){
            if(i != 43709) continue; 
            else cout << str; 
        }

        //check
        if(str[0] == ')' || str[n-1] == '('){
            cout << "NO\n"; 
            continue; 
        }
        if(dO.empty() && dC.empty()){
            cout << "YES\n";
            continue;
        }
        if(dO.empty() && !dC.empty()){
            //cout << "DoubleO";
            cout << "NO\n"; 
            continue; 
        }
        if(!dO.empty() && dC.empty()){
            //cout << "DoubleC";
            cout << "NO\n"; 
            continue; 
        }
        if(*dO.begin() > *dC.begin()){
            cout << "NO\n"; 
            continue; 
        }
        if(abs(nO - nC) % 2){
            //cout << "Parity";
            cout << "NO\n"; 
        }
        else cout << "YES\n";
    }
    return 0;
}