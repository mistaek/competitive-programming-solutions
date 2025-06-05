    /*
    1157B
    */
     
    #include <iostream>
    #include <vector>
     
    using namespace std; 
     
    int main(){
        //ios_base::sync_with_stdio(false); 
        //cin.tie(0); cout.tie(0); 
        int n; cin >> n; 
        vector<int> a, f(10); 
     
        for(int i = 0; i < n; ++i){
            char c; cin >> c; 
            //cout << c << " "; 
            a.push_back(c-'0'); 
            //cout << a[i] << " "; 
        }
        for(int i = 1; i <= 9; ++i) cin >> f[i]; 
     
        int state = 0;
        for(int i = 0; i < n; ++i){
            if(state == 0){
                if(f[a[i]] > a[i]){
                    a[i] = f[a[i]]; 
                    state = 1; 
                }
            }
            else if(state == 1){
                if(f[a[i]] >= a[i]){
                    a[i] = f[a[i]]; 
                }
                else state = 2; 
            }
            cout << a[i]; 
        }
     
        cout << "\n";
     
     
        return 0;
    }