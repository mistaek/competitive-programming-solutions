    /*
    1156A
    this problem is kinda dumb..
    or maybe i am..
    */
     
    #include <iostream>
    #include <vector>
     
    using namespace std; 
     
    int main(){
        int n; cin >> n; 
        int ans = 0; 
        int a[n]; 
        cin >> a[0]; 
        for(int i = 1; i < n; ++i){
            cin >> a[i]; 
            if(a[i] + a[i-1] > 4){
                ans = -1; break; 
            }
            ans += a[i] + a[i-1]; 
            if(i >= 2 && a[i-2] == 3 && a[i-1] == 1 && a[i] == 2) --ans; 
        }
     
        if(ans == -1) cout << "Infinite\n"; 
        else cout << "Finite\n" << ans << "\n"; 
        return 0;
    }