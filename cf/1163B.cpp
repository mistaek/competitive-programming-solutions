/*
1163A
*/

#include <iostream>
#include <vector>
#include <set>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 

    int n; cin >> n; 
    vector<int> numAppearances(1e5+1, 0); //number of appearances of each color. there are 1e5 colors
    vector<int> numCount(1e5+1, 0); //number of colors which have appeared i times. 
    numCount[0] = 1e5+1; 
    set<int> curActive; // counts for which some COUNTS some colors currently exist  
    int best = 1; // can always erase first element
    for(int i = 0; i < n; ++i){ 
        int u; cin >> u; 
        --numCount[numAppearances[u]]; // U CURRENTLY APPEARS NUMAPP[U] TIMES, NOW IT DOES NOT
        if(numCount[numAppearances[u]] == 0) curActive.erase(numAppearances[u]); //IF NO MORE COLORS OCCUR THIS MANY TIMES, ERASE
        ++numAppearances[u]; // U APPEARS NUMAPP[U] + 1 TIMES 
        if(numCount[numAppearances[u]] == 0) curActive.insert(numAppearances[u]); // IF THIS COUNT CURRENTLY DOESN'T EXIST, INSERT IT 
        ++numCount[numAppearances[u]];

        // IF THERE ARE 3 OR MORE CURRENTLY ACTIVE COUNTS, IMPOSSIBLE (CAN ONLY CHANGE ONE)
        if(curActive.size() == 2){ 
            int a = *curActive.begin(), b = *next(curActive.begin()); // A < B
            if(numCount[b] == 1 && a == b-1) best = i+1; // WE CAN DECREMENT B
            else if(a == 1 && numCount[a] == 1) best = i+1; 
        }
        else if(curActive.size() == 1 && *curActive.begin() == 1){
            best = i+1; // can just erase one color
        }
        else if(curActive.size() == 1 && numCount[*curActive.begin()] == 1) best = i+1;
    }
    cout << best << "\n";

    return 0;
}