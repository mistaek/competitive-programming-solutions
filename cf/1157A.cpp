    /*
    1157A
    */
     
    #include <iostream>
    #include <map>
     
    using namespace std; 
     
    int main(){
        int n; cin >> n; 
        map<int, int> seen; 
        int ans = 0;
        while(seen.find(n) == seen.end()){
            seen[n] = 1; 
            ++n; ++ans; 
            while(n % 10 == 0) n/=10;
        }
     
        cout << ans << "\n";
        return 0;
    }