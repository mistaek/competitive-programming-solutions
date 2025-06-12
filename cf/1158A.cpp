    /*
    1158A
    */
     
    #include <iostream>
    #include <vector>
     
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
        long long ans = 0;
        long long n, m; cin >> n >> m; 
        long long maxb = 0, maxb2 = 0;
        for(int i = 0; i < n; ++i){
            long long bi; cin >> bi; 
            ans += bi * m;
            if(bi >= maxb){
                maxb2 = maxb; 
                maxb = bi; 
            }
            else if(maxb2 <= bi){
                maxb2 = bi; 
            }
        }
        bool pos = true; 
        bool eq = false; 
        for(int j = 0; j < m; ++j){
            long long gi; cin >> gi; 
            if(gi < maxb) pos = false;
            if(gi == maxb) eq = true;  
            if(gi > maxb){
            	if(!eq && j == m-1){
                    ans += gi - maxb2; 
                }
                else ans += gi - maxb; 
            }
        
        }
     
        if(pos) cout << ans << "\n"; 
        else cout << "-1\n"; 
        return 0;
    }