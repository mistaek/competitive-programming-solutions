/*
1903E
AC
*/

#include <iostream>
#include <set>

using namespace std; 

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; 
        int sx, sy; 
        cin >> sx >> sy; 
        int start = (sx + sy)%2; 
        set<int> o[2]; 
        for(int i = 0; i < n; i++){
            int x, y; cin >> x >> y; 
            o[(x+y)%2].insert(i+1);
        }
        //cout << o[0].size() << " " << o[1].size() << endl;
        if(o[start].size() >= o[1-start].size()){
            cout << "First" << endl; 
            int ctr = 0;
            while(ctr < n){
                if(!o[1-start].empty()){
                    auto it = o[1-start].begin(); 
                    cout << *it << endl; 
                    o[1-start].erase(it);
                    ctr++;
                }
                else{
                    auto it = o[start].begin(); 
                    cout << *it << endl; 
                    o[start].erase(it); 
                    ctr++; 
                }
                if(ctr == n) break; 
                int in; cin >> in; 
                o[0].erase(in); o[1].erase(in);
                ctr++;
            }
        }
        else{
            cout << "Second" << endl; 
            int ctr = 0; 
            while(ctr < n){
                int in; cin >> in; 
                o[0].erase(in); o[1].erase(in);
                ctr++;
                if(ctr == n) break; 
                if(!o[start].empty()){
                    auto it = o[start].begin(); 
                    cout << *it << endl; 
                    o[start].erase(it);
                    ctr++;
                }
                else{
                    auto it = o[1-start].begin(); 
                    cout << *it << endl; 
                    o[1-start].erase(it); 
                    ctr++; 
                }
            }
        }
        


    }
    return 0;
}