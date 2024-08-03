/*
1856D
AC :o
*/
#include <iostream>
#include <set>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n;
        set<int> pos;  
        for(int i = 1; i <= n; i++){
            pos.insert(i);
        }
        int ctr = 0;
        while(pos.size() != 1){
            int r1, r2; 
            if(pos.size() % 2){
                auto p1 = prev(prev(pos.end())), p2 = prev(pos.end());
                cout << "? " << *p1 << " " << *p2 << endl; 
                cin >> r1; 
                if(r1 == -1) return 0;
                if(*p2 - *p1 > 2){
                    cout << "? " << *p1 + 1 << " " << *p2 - 1 << endl; 
                    cin >> r2; 
                    if(r2 == -1) return 0;
                    if(r1 >= r2 + *p2 - *p1){
                        pos.erase(p2);
                    }
                    else{
                        pos.erase(p1);
                    }
                }
                else{
                    if(r1 >= *p2 - *p1){
                        pos.erase(p2); 
                    }
                    else{
                        pos.erase(p1);
                    }
                }
            }

            auto p1 = pos.begin(); 
            while(p1 != pos.end()){
                auto p2 = next(p1); 
                cout << "? " << *p1 << " " << *p2 << endl; 
                cin >> r1; 
                if(r1 == -1) return 0;
                if(*p2 - *p1 > 2){
                    cout << "? " << *p1 + 1 << " " << *p2 - 1 << endl; 
                    cin >> r2; 
                    if(r2 == -1) return 0;
                    if(r1 >= r2 + *p2 - *p1){
                        p1 = pos.erase(p2);
                    }
                    else{
                        p1 = next(pos.erase(p1));
                    }
                }
                else{
                    if(r1 >= *p2 - *p1){
                        p1 = pos.erase(p2); 
                    }
                    else{
                        p1 = next(pos.erase(p1));
                    }
                }
            }
        }
        cout << "! " << *pos.begin() << endl; 
    }
    return 0;
}