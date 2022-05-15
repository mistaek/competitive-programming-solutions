#include <map>
#include <set>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std; 

int main(){
    int cases; 
    scanf("%d", &cases);
    cin.ignore(); 
    cin.ignore(); 
    while(cases--){
        string tree; int ind = 0;float count[10001] = {}, total = 0.0; map<string, int> keys; set<string> trees; string names[10001] = {}; 
        while(getline(cin, tree)){
            total+=1.0; 
            if(tree[0] == '\0') break; 
            if(trees.count(tree) == 0){
                trees.insert(tree);
                keys[tree] = ind; 
                names[ind] = tree; 
                count[ind] = 0.0;
                ind++; 
            }
            count[keys[tree]]+=1.0; 
        } 
        sort(names, names+10000);
        for(int i = 0; i < ind; i++){
        	cout << names[i] << " "; 
            cout <<  fixed << setprecision(4) << (count[keys[names[i]]] / total)*100.0000 << "\n"; 
        }
        if(cases) printf("\n"); 
    }
    return 0; 
}

// too complex, a map is all you need!