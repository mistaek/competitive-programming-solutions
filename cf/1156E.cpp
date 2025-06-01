    /*
    1156E
    */
     
    #include <iostream>
    #include <vector>
     
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
     
        int n; cin >> n; 
        vector<int> p, biggerBefore, biggerAfter, invp; 
        p = biggerBefore = invp = vector<int>(n+2, 0); 
        biggerAfter = vector<int>(n+2, n+1); 
     
        for(int i = 1; i <= n; ++i){
            cin >> p[i]; 
            invp[p[i]] = i; 
        }
     
        // is htis o(N)???
        for(int i = 2; i <= n; ++i){
            int cur = i-1; 
            while(cur != 0){
                if(p[cur] > p[i]){
                    break; 
                }
                cur = biggerBefore[cur]; 
            }
            biggerBefore[i] = cur; 
        }
     
        for(int i = n-1; i >= 1; --i){
            int cur = i+1; 
            while(cur != n+1){
                if(p[cur] > p[i]) break; 
                cur = biggerAfter[cur]; 
            }
            biggerAfter[i] = cur; 
        }
     
        long long ans = 0;
        for(int i = 2; i < n; ++i){
            if(i - biggerBefore[i] < biggerAfter[i] - i){
                for(int j = biggerBefore[i] + 1; j < i; ++j){
                    if(i < invp[p[i] - p[j]] && invp[p[i] - p[j]] < biggerAfter[i]) ++ans; 
                }
            }
            else{
                for(int j = biggerAfter[i] - 1; j > i; --j){
                    if(i > invp[p[i] - p[j]] && invp[p[i] - p[j]] > biggerBefore[i]) ++ans; 
                }
            }
        }
        cout << ans << "\n"; 
        return 0;
    }