    /*
    1156B
     
    */
     
    #include <iostream>
    #include <vector>
    #include <set> 
    #include <algorithm>
     
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
     
        int t; cin >> t; 
        while(t--){
            string s; 
            cin >> s; 
            vector<char> letters; 
            int cnt[26] = {};
            for(char c : s){
                if(cnt[c-'a'] == 0){
                    letters.push_back(c); 
                }
                ++cnt[c-'a']; 
            }
     
            sort(letters.begin(), letters.end()); 
            string ans; 
            if(letters.size() >= 4){
                for(int i = 1; i < letters.size(); i +=2){
                    for(int j = 0; j < cnt[letters[i]-'a']; ++j) ans.push_back(letters[i]); 
                }
                for(int i = 0; i < letters.size(); i +=2){
                    for(int j = 0; j < cnt[letters[i]-'a']; ++j) ans.push_back(letters[i]); 
                }
                
                cout << ans << "\n"; 
            }
            else{
                //check all perms cause hwy not
                bool pos = true; 
                do{
                    pos = true; 
                    for(int i = 1; i < letters.size(); ++i){
                        if(letters[i] == letters[i-1] + 1 || letters[i]+1== letters[i-1]) pos = false; 
                    }
                    if(pos){
                        break; 
                    }
                } while(next_permutation(letters.begin(), letters.end())); 
                if(pos){
                    for(char c : letters) for(int i = 0; i < cnt[c-'a']; ++i) ans.push_back(c); 
                }
                else ans = "No answer"; 
                cout << ans << "\n"; 
            }   
        }
        return 0;
    }