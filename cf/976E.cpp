/*
976E
AC
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std; 

struct Minion{
    long long hp;
    long long atk;
};

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b; cin >> n >> a >> b; 
    b = min(b, n);
    vector<Minion> minions; 
    long long total = 0, usedSwaps = 0;

    for(int i = 0; i < n; ++i){
        int hp, dmg; cin >> hp >> dmg; 
        minions.push_back({hp, dmg});
        total += dmg;
    }
    auto compareMinions = [](const Minion& a, const Minion& b){
        return a.hp - a.atk > b.hp - b.atk; 
    };
    sort(minions.begin(), minions.end(), compareMinions);

    for(int i = 0; i < b; ++i){
        if(minions[i].hp - minions[i].atk > 0){
            total += minions[i].hp - minions[i].atk;
            ++usedSwaps;
        }
    }

    long long ans = total;
    for(int i = 0; i < n; ++i){
        if(i < usedSwaps){
            long long newans = total - minions[i].hp;
            newans += (1LL << a) * minions[i].hp;
            ans = max(ans, newans);
        }
        else{
            if(usedSwaps < b){
                long long newans = total - minions[i].atk; 
                newans += (1LL << a) * minions[i].hp; 
                ans = max(ans, newans);
            }

            else if(usedSwaps == b && b > 0){
                long long newans = total - minions[usedSwaps - 1].hp + minions[usedSwaps-1].atk; //unswap last
                newans += (1LL << a) * minions[i].hp - minions[i].atk; //swap this minion
                ans = max(ans, newans);
            }
        }
    }
    cout << ans << "\n";

    
    return 0;
}