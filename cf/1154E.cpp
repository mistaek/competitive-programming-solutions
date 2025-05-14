    /*
    1154E
    */
     
    #include <iostream>
    #include <list> 
    #include <map>
    #include <vector>
    #include <functional>
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
        int n, k; cin >> n >> k; 
        list<int> a; 
        vector<int> ans(n, 0); 
        map<int, list<int>::iterator> links; //should be sorted
        map<int, int> idx; 
        for(int i = 0; i < n; ++i){
            int ai; cin >> ai; 
            a.push_back(ai); 
            links[ai] = prev(a.end()); 
            idx[ai] = i; 
        }
     
        function<void(list<int>::iterator)> rem = [&](list<int>::iterator it){
            links.erase(*it); 
            a.erase(it); 
        };
     
        int turn = 0; 
        while(!links.empty()){
            auto [id, it] = *prev(links.end());
            auto tm = next(it); 
            for(int i = 0; i < k; ++i){
                if(tm == a.end()) break; 
                ans[idx[*tm]] = 1 + turn; 
                tm = next(tm); 
                rem(prev(tm)); 
            }        
            
            tm = it; 
     
            for(int i = 0; i < k+1; ++i){
                ans[idx[*tm]] = 1 + turn; 
                
                if(tm == a.begin()){
                    rem(tm); 
                    break;
                }; 
                tm = prev(tm); 
                rem(next(tm));             
            }
     
            turn = 1-turn; 
        }
     
        for(int i = 0; i < n; ++i){
            cout << ans[i]; 
        }
        cout << "\n"; 
        
        return 0;
    }