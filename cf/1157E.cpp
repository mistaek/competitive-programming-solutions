    /*
    1157E
    */
     
    #include <iostream>
    #include <set>
    #include <vector>
    #include <algorithm>
     
    using namespace std; 
     
    int main(){
        int n; cin >> n; 
        vector<int> a(n); 
        multiset<int> b; 
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }
        for(int i = 0; i < n; ++i){
            int bi; cin >> bi; 
            b.insert(bi); 
        }
     
        for(int i = 0; i < n; ++i){
            if(i) cout << " "; 
            int inv = n - a[i]; 
            inv %= n; //special case for 0
            auto it = b.lower_bound(inv); 
            if(it != b.end()){
                cout << (a[i] + *it) %n; 
                b.erase(it); 
            }
            else{
                cout << (a[i] + *b.begin()) %n; 
                b.erase(b.begin()); 
            }
        }
        cout << "\n"; 
        return 0;
    }