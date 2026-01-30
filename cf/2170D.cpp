/*
2170D
*/

#include <iostream>
#include <string>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, q; cin >> n >> q; 

        string s; cin >> s;
        s.push_back('I'); // nothingburger value to push back 
        int base = 0;

        int totalQ = 0;
        int iqi, iqv, vqi, vqv;
        iqi = iqv = vqi = vqv = 0;
        int block = 0, totalBlock =0;
        bool inBlock = 0;
        for(int i = 0; i < n; ++i){
            if(s[i] == '?'){
                ++totalQ;
                if (inBlock){
                    if(s[i+1] == '?') ++block; 
                    else if(s[i+1] == 'I'){
                        ++block; 
                        inBlock = false; 
                        totalBlock += block/2; 
                        block = 0;
                    }
                    else {
                        ++vqv; 
                        inBlock = false; 
                        totalBlock += block/2; 
                        block = 0;
                    }
                } 
                else {
                    if(s[i+1] == 'V' || s[i+1] == 'X'){
                        if(i && s[i-1] == 'I') ++iqv; 
                        else ++vqv; 
                    }
                    else if(s[i+1] == 'I'){
                        if(i && s[i-1] == 'I') ++ iqi; 
                        else ++vqi;
                    }
                    else {
                        if (i == 0 || s[i-1] != 'I'){
                            inBlock = true; 
                            ++block; 
                        }
                        else {
                            ++iqi;
                        }
                    }
                }
            }
            if(s[i] == 'V') base +=5; 
            if(s[i] == 'I') {
                if(i < n-1 && (s[i+1] == 'V' || s[i+1] == 'X')) base -=2;
                base += 1; 
            }
            if(s[i] == 'X') base += 10; 
        }

        for(int i = 0; i < q; ++i){
            int cx, cv, ci; cin >> cx >> cv >> ci; 
            int useI = min(ci, totalQ), useV = min(cv, totalQ-useI), useX = min(cx, totalQ - useI - useV); 
            int qBase = base + useI + 5*useV + 10*useX; 
            /*
            cout << "QBASE START " << qBase << "\n";
            cout << useI << " " << useV << " " << useX << "\n";
            cout << "VQVs: " << vqv << " IQIs: " << iqi << "\n";
            cout << "totalBlock: " << totalBlock << "\n";
            cout << "iqv: " << iqv << "\n";
            //*/
            int useVX = useV + useX;
            {
                // first: fill out as many iqi, vqv 
                qBase -= 2*min(vqv, useI); 
                useI -= min(vqv, useI); 
                qBase -= 2*min(useVX, iqi); 
                useVX -= min(useVX, iqi);  
                
                // second: fill out blocks 
                qBase -= 2*min(min(useI, useVX), totalBlock);
                
                // iqv is always -2
                qBase -= 2*iqv; 
            }

            cout << qBase << "\n";
        }
    }
    return 0;
}