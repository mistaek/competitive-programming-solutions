/*
1023E
AC
*/

#include <iostream>
#include <string>

using namespace std; 

int main(){
    int n; cin >> n; 
    string s(2*(n-1), '*');
    int path = 0, idx = 2*(n-1) - 1;
    int total = 0;
    pair<int, int> cur = {1, 1}, goal = {n, n}; 
    pair<int, int> meetpt; 
    string ans; 
    while(total < 2*(n-1)){
        if(total < (n-1)){
            cout << "? " << cur.first + 1 << " " << cur.second << " " << goal.first << " " << goal.second << endl;
            cin >> ans; 
            if(ans == "YES"){
                s[path] = 'D'; 
                cur.first += 1; 
            }
            else{
                s[path] = 'R';
                cur.second += 1; 
            }
            path++;
            meetpt = cur; 
        }
        //we have traveled n steps
        else{
            //above, we move down whenever possible, so we are goign to the down leftest
            //here move left whenever possible
            cout << "? " << 1 << " " << 1 << " " << goal.first << " " << goal.second - 1 << endl; 
            cin >> ans; 
            if(ans == "YES"){
                goal.second -= 1; 
                s[idx--] = 'R';
            }
            else{
                goal.first -= 1; 
                s[idx--] = 'D';
            }
        }
        total++; 
    }
    cout << "! " << s << endl; 
    return 0;
}
