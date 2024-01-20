/*
1886C
AC
*/

#include <iostream>
#include <string>
#include <stack>

using namespace std; 

int main(){
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t; 
    while(t--){
        string s; cin >> s; 
        long long pos; cin >> pos;
        long long curlen = s.length(), rem = 0; 
        while(pos > curlen){
            pos -= curlen;
            --curlen; 
            ++rem; 
        }
        //cout << pos << " " << rem << "\n";
        int j = 0;
        stack<char> srt;
        for(int i = 0; i < s.length(); ++i){
            while(!srt.empty() && j < rem && srt.top() > s[i]){
                srt.pop(); 
                j++; 
            }
            srt.push(s[i]); 
        }
        while(j < rem || srt.size() > pos){ //pop until we find pos
            srt.pop(); 
            j++; 
        }
        cout << srt.top();
    }
    cout << "\n";
    return 0;
}