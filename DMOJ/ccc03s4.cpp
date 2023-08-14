/*
ccc 03 s4
ac
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

int n, classes, alphabet = 256; 
vector<int> p, c, count; 
string s; 

void construct(){
    p.assign(n,0); c.assign(n,0); count.assign(max(alphabet,n), 0);
    for(int i = 0; i < n; i++) count[s[i]]++; 
    for(int i = 1; i < alphabet; i++) count[i] += count[i-1];
    for(int i = 0; i < n; i++) p[--count[s[i]]] = i;

    classes = 1; c[p[0]] = 0;
    for(int i = 1; i < n; i++){
        if(s[p[i]] != s[p[i-1]]) 
            classes++; 
        c[p[i]] = classes-1; 
    }

    // 

    vector<int> pn(n, 0), cn(n, 0);
    for(int l = 0; (1 << l) < n; l++){
        fill(count.begin(), count.begin() + classes, 0); 
        
        for(int i = 0; i < n; i++){
            pn[i] = p[i] - (1 << l); 
            if(pn[i] < 0) 
                pn[i] += n; 
        }

        for(int i = 0; i < n; i++)
            count[c[pn[i]]]++;
        
        for(int i = 1; i < classes; i++)
            count[i] += count[i-1]; 
        
        for(int i = n-1; i >= 0; i--)
            p[--count[c[pn[i]]]] = pn[i];

        cn[p[0]] = 0; classes = 1; 
        for(int i = 1; i < n; i++){
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1<<l)) %n]};
            pair<int, int> pre = {c[p[i-1]], c[(p[i-1] +(1<<l)) %n]};
            if(cur != pre)
                classes++;
            cn[p[i]] = classes-1;
        }
        c.swap(cn);
    }
}

vector<int> lcp, rnk; //lcp stuff
void constructlcp(){
    lcp.assign(n,0); rnk.assign(n,0);
    for(int i = 0; i < n; i++)
        rnk[p[i]] = i; // basically value -> index for p array

    int k = 0; // lcp value tracker
    for(int i = 0; i < n; i++){ // actual operation array
        if(rnk[i] == n-1){ //if current index is last in p array, it has lcp 0 
            k = 0; 
            continue;
        }

        int j = p[rnk[i] + 1]; //second index is equal to next lexographically minimal suffix which is stored in p 
        while(i + k < n && j + k < n && s[i+k] == s[j+k]) 
            k++; //while i+k and j+k are legal and the string values are same, increment k
        lcp[rnk[i]] = k; //use rank as lcp[i] corresponds to index i of p
        if(k) 
            k--;
    }
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        cin >> s; s+= '$'; n = s.length();
        construct(); //return 0; 
        // /for(int a : p)  //return 0;
        constructlcp(); 
        int ans = 1; ans+= n - p[1] - 1; 
        for(int i = 2; i < n; i++){ // start at 2 to avoid the whole $ thing
            ans += n - p[i] - 1 - lcp[i-1]; 
        }
        printf("%d\n", ans);
    }

    return 0;
}