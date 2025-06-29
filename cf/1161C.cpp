    /*
    1161C
    */
     
    #include <iostream>
    #include <vector>
    #include <map>
     
    using namespace std; 
     
    int main(){
        int n; cin >> n; 
        map<int, int> cnt; 
        for(int i = 0; i < n; ++i){
            int a; cin >> a; 
            cnt[a]++; 
        }
     
        if(cnt.begin()->second > n/2){
            cout << "Bob\n"; 
        }
        else cout << "Alice\n"; 
        return 0;
    }