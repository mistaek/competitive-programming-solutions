    /*
    1158B
    */
     
    #include <iostream>
     
    using namespace std; 
     
    int main(){
        int n, k; cin >> n >> k; 
        int x = (n -k)/2 + 1; 
     
        for(int i = 0; i < n; ++i){
            if((i+1) % x == 0) cout << 1; 
            else cout << 0; 
        }
        cout << "\n"; 
        return 0;
    }