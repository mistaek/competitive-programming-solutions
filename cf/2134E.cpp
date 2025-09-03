/*
2134E
*/
    
#include <iostream>
#include <vector>
    
using namespace std; 
int main(){
    
    int tc; cin >> tc; 
    while(tc--){
        int n; cin >> n; 
        vector<int> curState(n+1, 0), OG(n+1, 0), untilEnd(n+3, 0);
    
        cout << "throw " << n-1 << endl; 
        int resp; cin >> resp; 
        if(resp == 2) OG[n-1] = curState[n-1] = 1; 
        else OG[n-1] = curState[n-1] = 2; 
        cout << "swap " << n-1 << endl; 
        swap(curState[n-1], curState[n]); 
        cout <<"throw " << n-1 << endl; 
        cin >> resp; 
        if(resp == 2){
            OG[n] = curState[n-1] = 1; 
        }
        else{
            OG[n] = curState[n-1] = 2; 
        }
        untilEnd[n] = untilEnd[n-1] = 1; 
        if(curState[n-1] == 1) ++untilEnd[n-1]; 
    
        auto swapS = [&](int i){
            int j = i+1; 
            cout << "swap " << i << endl; 
            swap(curState[i], curState[j]); 
            untilEnd[i] = 1 + untilEnd[i + curState[i]]; 
            untilEnd[j] = 1 + untilEnd[j + curState[j]]; 
        };
        auto throwS = [&](int i, int bnc1, int bnc2){
            cout << "throw " << i << endl; 
            cin >> resp; 
            if(resp == bnc1){
                curState[i] = 1; 
                untilEnd[i] = bnc1; 
            }
            else{
                curState[i] = 2; 
                untilEnd[i] = bnc2; 
            }
        };
        int cur = n-2; // trying to determine value of this index
        int q = 3; 
        while(cur >= 1){
            /*
            cout << "CUR STATE ";
            for(auto v : curState) cout << v << " "; 
            cout << endl; 
            for(auto v : untilEnd) cout << v << " " ; 
            cout << endl << "\n";
            //*/
            int bnc1 = 1 + untilEnd[cur +1], bnc2 = 1 + untilEnd[cur+2]; 
            if(bnc1 != bnc2){
                // swap cur with cur - 1 if possible
                throwS(cur, bnc1, bnc2); 
                OG[cur] = curState[cur]; 
                ++q; 
                cur--; 
            }
            else{
                if(cur > 1){
                    bnc1++; 
                    throwS(cur-1, bnc1, bnc2); 
                    OG[cur-1] = curState[cur-1]; 
                    swapS(cur-1);
                    throwS(cur-1, bnc1, bnc2); 
                    OG[cur] = curState[cur-1];  
                    q += 3; 
                    cur -= 2; 
                }
                else{
                    swapS(1); 
                    bnc1 = 1 + untilEnd[3], bnc2 = 1 + untilEnd[4]; 
                    throwS(2, bnc1, bnc2); 
                    OG[1] = curState[2]; 
                    q+= 2; 
                    cur--; 
                }
            }
        }
        //cout << "QUERIES USED " << q << endl; 
        cout << "!"; 
        for(int i = 1; i <= n; ++i){
            cout << " " << OG[i]; 
        }
        cout << "\n"; 
    
    
    
    }
    return 0;
}