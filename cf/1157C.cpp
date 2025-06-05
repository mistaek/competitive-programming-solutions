    /*
    1157C
    */
     
    #include <iostream>
    #include <vector>
     
    using namespace std; 
     
    int main(){
        ios_base::sync_with_stdio(false); 
        cin.tie(0); cout.tie(0); 
        int n; cin >> n; 
        vector<int> a(n); 
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
     
        int last = -1; 
        vector<char> moves; 
        int l = 0, r = n-1; 
        while(l <= r){
            if(a[l] <= last && a[r] <= last) break; 
            if(a[l] <= last){
                moves.push_back('R'); 
                last = a[r]; 
                --r; 
            }
            else if(a[r] <= last){
                moves.push_back('L'); 
                last = a[l]; 
                ++l; 
            }
            else if(a[l] < a[r]){
                moves.push_back('L'); 
                last = a[l]; 
                ++l; 
            }
            else if(a[r] < a[l]){
                moves.push_back('R'); 
                last = a[r]; 
                --r; 
            }
            else{
                int tl = l+1, lans = 1, tr = r-1, rans = 1; 
                while(tl <=r && a[tl] > a[tl-1]){
                    ++tl; 
                    ++lans; 
                }
                while(tr >= l && a[tr] > a[tr + 1]){
                    --tr; 
                    ++rans; 
                }
                if(rans >= lans){
                    for(int i = 0; i < rans; ++i) moves.push_back('R'); 
                }
                else{
                    for(int i =0; i < lans; ++i) moves.push_back('L'); 
                }
                break; 
            }
     
        }
     
        cout << moves.size() << "\n"; 
        for(char c : moves) cout << c; 
        cout << "\n";
     
     
        return 0;
    }