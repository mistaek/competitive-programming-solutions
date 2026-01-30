/*
2183C
*/

#include <iostream>
#include <vector>

using namespace std; 

int main(){
    int t; cin >> t; 
    while(t--){
        long long n, m, k; cin >> n >> m >> k;
        long long downward = k-1, upward = n-k;

        //direction doesn't really matter
        long long ans = 1;
        if(downward > upward) swap(downward, upward);
        //cout << downward << " " << upward << "\n";
        // takes x-1 + x moves to cover x in some direction
        if(n == 1) {
            cout << "1\n";
            continue;
        }
        if(m == 1) {
            cout << 2 << "\n";
            continue;
        }
        else {
            int y = (m-2)/3;
            if((m-2)%3) ++y;
            //cout << y << "\n";
            // down
            
            if(downward < y+1) {
                m -= 2*(downward) - 1;
                ans = 1 + downward; 
                // m days to move as far up as possible with downward starting troops
                y = max(0LL, m - downward)/2;
                if(m-downward > 0 && (m-downward) %2) ++y;
                ans += min(upward, m-y);
            }
            else {
                ans = min(n, m - y + 1);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}