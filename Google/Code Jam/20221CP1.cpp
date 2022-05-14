/*
ac - missed a case and tilt submitted lol
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <map>

using namespace std; 
int main(){
    int TC; cin >> TC;
    for(int tc = 1; tc <= TC; tc++){
        printf("Case #%d: ", tc);
        int n;
        cin >> n;
        string blocks[n];
        for(int i = 0; i < n; i++){
            cin >> blocks[i];
        }

        int a[n] = {}, ans = 0;
        string out, temp, outt;
        for(int i = 0; i < n; i++){
            if(blocks[i][0] != blocks[i][blocks[i].length() - 1]){
                out = blocks[i]; 
                ans = 1;
                a[i] = 1;
                break;
            }
        }
        if(ans == 0){
        	out = blocks[0]; a[0] = 1;
        }
        
        ans = 0; int rd = 0;
        for(int i = 1; i < n; i++){
            rd = 0;
            for(int j = 0; j < n; j++){
                if(blocks[j][0] == out[out.length() - 1] && blocks[j][blocks[j].length()- 1] == blocks[j][0] && a[j] == 0){
                    out += blocks[j]; 
                    a[j] = 1; 
                    rd = 1; 
                    break; 
                }
                else if(blocks[j][blocks[j].length() -1] == out[0] && blocks[j][blocks[j].length()- 1] == blocks[j][0] &&  a[j] ==0){
                    temp = out; 
                    out.clear();
                    out = blocks[j]; 
                    out += temp;
                    a[j] = 1; rd = 1; 
                    break; 
                }
            }
            if(rd == 0){
            for(int j = 0 ; j < n; j++){
                if(blocks[j][0] == out[out.length() - 1] && a[j] == 0){ 
                    out += blocks[j]; 
                    a[j] = 1; rd = 1; 
                    break; 
                }
                else if(blocks[j][blocks[j].length() -1] == out[0] && a[j] ==0){
                    temp = out; 
                    out.clear();
                    out = blocks[j]; 
                    out += temp;
                    a[j] = 1; rd = 1; 
                    break; 
                }
            }
            }
            if(rd == 0){
            	outt+= out; 
            	out.clear(); 
                for(int j = 0; j < n; j++){
                    if(a[j] == 0){
                        out = blocks[j];
                        a[j] = 1; 
                        break;
                    }
                }
            }
            
            if(i == n-1) outt += out; 
        }
        
        int u[26] = {};
        for(int i = 0; i < outt.length(); i++){
            if(u[outt[i] - 'A'] && outt[i] != outt[i-1] ){
            	ans = -1; 
            }
            u[outt[i] - 'A'] = 1; 
        }
        if(ans == -1) printf("IMPOSSIBLE\n"); 
        else cout << outt << "\n";
    }
    return 0;
}