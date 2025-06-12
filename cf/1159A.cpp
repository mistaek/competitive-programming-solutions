    /*
    1159A
    */
     
    #include <iostream>
    #include <algorithm>
     
    using namespace std; 
     
    int main(){
        int n; cin >> n; 
        int bal = 0, minbal = 0; 
        for(int i = 0; i < n; ++i){
            char c; cin >> c; 
            if(c == '-') --bal; 
            else ++bal; 
            minbal = min(bal, minbal); 
        }
     
        cout << -1 * minbal  + bal<< "\n";
        return 0;
    }