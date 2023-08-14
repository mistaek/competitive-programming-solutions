/*
1800E2
AC
*/


#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std; 
int n, k;
vector<int> ufds; 

int find(int a){
    if(ufds[a] == a) return a; 
    else return ufds[a] = find(ufds[a]);
}

void unite(int a, int b){
    if(a >= n || a < 0 || b >= n || b < 0 ) return; 
    int s1 = find(a), s2 = find(b); 
    if(find(a) != find(b)){
        if(s1 < s2){
            ufds[s2] = s1; 
        }
        else{
            ufds[s1] = s2; 
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 

    int t; 
    cin >> t; 
    while(t--){
         cin >> n >> k; 
        string s1, s2; 
        cin >> s1 >> s2; 

        ufds.clear(); ufds.resize(n);
        for(int i = 0; i < n; i++){
            ufds[i] = i; 
        }
        for(int i = 0; i < n; i++){
            unite(i, i+k); 
            unite(i, i+k+1);
            unite(i, i-k); 
            unite(i, i-k-1);
        }
        map<int, vector<int>> charset; 
        for(int i = 0; i < n; i++){
            //cout << ufds[i] << " "; 
            if(charset.find(ufds[i]) ==charset.end()){
                charset[ufds[i]].resize(26, 0); 
                charset[ufds[i]][s1[i]- 'a']++;
            }
            else{
                charset[ufds[i]][s1[i] - 'a']++;
            }
        }
        //cout << "\n";
        bool ans = true; 
        for(int i = 0; i < n; i++){
            if(charset[ufds[i]][s2[i] - 'a']){
                charset[ufds[i]][s2[i] - 'a']--;
            }
            else{
                //cout << "fails at " << i << "\n";
                //cout << s2[i] << " " << charset[ufds[i]][s2[i] - 'a'] << "\n";
                ans = false; 
                cout << "no\n"; 
                break; 
            }
        }
        if(ans) cout << "yes\n";
    }
    return 0;
}