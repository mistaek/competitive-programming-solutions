    /*
    1654C
    */
     
    #include <iostream>
    #include <map>
    #include <vector>
    #include <stack>
    #include <queue>
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int t; cin>>t; 
         
        
        while(t--){
            int n; cin >> n;
            map<long long, int> occ; 
            
            
            long long sum = 0; 
            for(int i = 0; i < n; i++){
                long long in; cin >> in; 
                sum += in; 
                if(occ.count(in) == 0) occ[in] = 1; 
                else occ[in]++; 
            }
     
            bool ans = 1; 
            stack<long long> q; 
            q.push(sum); 
            //memory issue
            while(!q.empty()){
                long long req = q.top(); q.pop(); 
                if(req == 0){
                    ans = 0;
                    break;
                }
                //potential time issue here?
                if(occ.count(req) && occ[req] > 0) occ[req]--; 
                else{
                    q.push((req/2) + (req % 2)); q.push(req/2); 
                }
            }
     
            if(ans) cout << "Yes" << endl; 
            else cout << "No" << endl; 
        }
        return 0;
    }