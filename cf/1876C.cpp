/*
1876C
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<int> a, indeg, rem, v; 
bool pos = true; 

void traverse(int u){
    if(v[u]) return; 
    v[u] = 1;
    if(!rem[u]) rem[a[u]] = 1; 
    if(!--indeg[a[u]]) traverse(a[u]);
}

int main(){
    cin.tie(0); 
    ios_base::sync_with_stdio(0);
    
    int n; cin >> n;
    a = v = rem = indeg = vector<int>(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        ++indeg[a[i]];
    }

    for(int i = 1; i <= n; i++){
        if(!v[i] && indeg[i] == 0){
            traverse(i); 
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(!v[i] && rem[i]){
            indeg[i] = 0;
            traverse(i);
        }
    }
    
    for(int i = 1; i <= n; i++){
        if(indeg[i] > 1) cout << "?\n";
        if(!v[i]){
            traverse(i); 
            if(rem[i]) pos = false; 
        }
    }
    if(pos){
        int opp = 0;
        for(int i = 1; i <= n; i++){
            if(!rem[i]) opp++;
        }
        cout << opp << "\n";
        bool outed = false; 
        for(int i = 1; i <= n; i++){
            if(outed) cout << " "; 
            if(!rem[i]){
                cout << a[i]; 
                outed = true; 
            }
            else outed = false; 
        }
        cout << "\n";
    }
    else cout << "-1\n";
    return 0;
}