    /*
    1161B
    */
     
    #include <iostream>
    #include <vector>
    #include <set>
    #include <algorithm>
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
     
        int n, m; cin >> n >> m; 
        vector<pair<int, int>> pairs; 
        for(int i = 0; i < m; ++i){
            int a, b; cin >> a >> b; 
            if(a > b) swap(a, b); 
            if(b - a == n/2){
                pairs.push_back({a, b});
                pairs.push_back({b, a + n}); 
            }
            else if(b - a < n/2){
                pairs.push_back({a, b}); 
            }
            else pairs.push_back({b, a+n});
        }
        sort(pairs.begin(), pairs.end()); 
        //for(auto p : pairs) cout << p.first << " " << p.second << "\n";
        vector<int> str; 
        vector<int> back;
        int j = 0; 
        for(int i = 1; i <= n; ++i){
            str.push_back(0); 
            while(j < pairs.size() && i == pairs[j].first){
                int gap = pairs[j].second - i; 
                str.push_back(gap); 
                ++j; 
            }
           
        }
        //for(auto c : str) cout << c << " "; 
        back = vector<int>(str.size(), 0); //kmp back array
        int sz = str.size(); 
        j = 0; 
        str.push_back(str[0]); 
        for(int i = 1; i < sz; ++i){
            str.push_back(str[i]); 
            while(j){
                if(str[j] == str[i]) break; 
                else j = back[j-1];
            }
            if(str[j] == str[i]){
                back[i] = ++j; 
            }
        }
        bool found = false; 
        j = 0; 
        for(int i = 1; i < 2*sz - 1; ++i){
            while(j){
                if(str[i] == str[j]){
                    break; 
                } 
                else{
                    j = back[j-1]; 
                }
            }
            if(str[i] == str[j]){
                ++j; 
            }
            if(j == sz){
                found = true; break; 
            }
        }
        if(found) cout << "Yes\n"; 
        else cout << "No\n";
        
     
        return 0;
    }