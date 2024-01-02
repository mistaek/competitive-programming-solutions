/*
1904D2
AC
*/

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int a[n], b[n]; 
        for(int i = 0; i < n; i++) cin >> a[i];
        int ans = 1; 
        for(int i = 0; i < n; i++){
            cin >> b[i];
            if(b[i] < a[i]) ans = 0;
        }
        if(ans == 0){
            cout << "NO\n";
            continue; 
        }
        int mostrecent[n+1] = {}, viable[n]  ={}; 
        deque<int> biggies;
        for(int i = 0; i <= n; i++){
            mostrecent[i] = -1; 
        }
        for(int i = 0; i < n; i++){
            while(!biggies.empty() && a[i] > biggies.back()){
                mostrecent[biggies.back()] = -1; //mark unreachable
                biggies.pop_back();
            }
            while(!biggies.empty() && b[i] < biggies.front()){
                mostrecent[biggies.front()] = -1;
                biggies.pop_front();
            }
            if(biggies.empty() || (biggies.back() > a[i])) biggies.push_back(a[i]);
            mostrecent[a[i]]=i; 
            if(mostrecent[b[i]] != -1) viable[i] = 1; 
        }
        biggies.clear();
        for(int i = 0; i <= n; i++){
            mostrecent[i] = -1; 
        }
        for(int i = n-1; i >=0; i--){
            while(!biggies.empty() && a[i] > biggies.back()){
                mostrecent[biggies.back()] = -1; //mark unreachable
                biggies.pop_back();
            }
            while(!biggies.empty() && b[i] < biggies.front()){
                mostrecent[biggies.front()] = -1;
                biggies.pop_front();
            }
            if(biggies.empty() || (biggies.back() > a[i])) biggies.push_back(a[i]);
            mostrecent[a[i]]=i; 
            if(mostrecent[b[i]] != -1) viable[i] = 1; 
            //for(auto it : biggies) cout << it << " ";
            //cout << "\n";
        }
        for(int i = 0; i < n; i++){
            ans = min(ans, viable[i]); 
        }
        if(ans) cout << "YES\n"; 
        else cout << "NO\n";

    }
    return 0;
}