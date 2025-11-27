/*
1176D
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    // nlogn 
    bool notprime[200003] = {true, true}; 
    int invmap[200003] = {}, curctr = 2; 
    invmap[2] = 1; 
    for(int i = 4; i <= 200000; i+=2) notprime[i] = true; 
    for(int i = 3; i <= 200000; i+=2){
        if(!notprime[i]) {
            invmap[i] = curctr++; 
            if(i > 1000) continue; 
            for(int j = i*i; j <= 200000; j +=i) notprime[j] = true; 
        }
    }

    int bigdiv[200003] = {}; 
    for(int i = 2; i <= 200000; ++i){
        for(int j = 2*i; j <= 200000; j+=i) bigdiv[j] = i; 
    }

    int n; cin >> n; 
    multiset<int> primes, torem; 
    multiset<int, greater<int>> composites; 
    vector<int> a; 
    for(int i = 0; i < 2*n; ++i){
        int bi; cin >> bi; 
        if (bi > 200000) continue; 
        if(!notprime[bi]) primes.insert(bi); 
        else composites.insert(bi); 
    }

    while(!composites.empty()) {
        auto front = *composites.begin(); 
        a.push_back(front); 
        if (notprime[bigdiv[front]]) composites.erase(composites.find(bigdiv[front])); 
        else primes.erase(primes.find(bigdiv[front])); 
        composites.erase(composites.begin()); 
    }

    while(!primes.empty()) {
        auto front = *primes.begin(); 
        if (torem.find(invmap[front]) != torem.end()) {
            torem.erase(torem.find(invmap[front])); 
        }
        else {
            a.push_back(front);
            torem.insert(front); 
        }
        primes.erase(primes.begin()); 
    }
    
    for(int i = 0; i < n; ++i) {
        if(i) cout << " "; 
        cout << a[i]; 
    }
    cout << "\n"; 
    return 0;
}