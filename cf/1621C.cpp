/*
1621C
ac???????
*/

#include <cstdio>
#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        int p[n+1] = {}, c = -1; 
        cout << "? 1" << endl; 
        int resp, len = 1; cin >> resp;  
        vector<int> line;
        line.push_back(resp); 
        int ind = 1;
        while(ind <= n){
            if(p[ind] != 0){ ind++; continue; }
            cout << "? " << ind << endl;
            cin >> resp; 
            c++;
            if(resp == line[0]){
                int adj = (len - c);
                
                while(adj < 0) adj += len;
                //cout << len << " " << c << " " << adj << endl; 
                int ind2 = ind;
                for(int i = 0; i < len; i++){
                    p[ind2] = line[(adj + i) % len];
                    ind2 = p[ind2];
                }
                line.clear();
                len = 0;
            }
            else{ line.push_back(resp);len++;}
        }
        cout << "!"; 
        for(int i = 1; i <= n; i++){
            cout << " " << p[i];
        }
        cout << endl;
    }
    return 0;
}