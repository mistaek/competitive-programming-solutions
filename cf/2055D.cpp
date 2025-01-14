/*
2055D
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    int t; cin >> t; 
    while(t--){
        int n, k, l; cin >> n >> k >> l; 
        vector<double> a(n); 
        double time = 0, cur = 0;
        for(int i = 0; i < n; ++i){
            cin >> a[i]; 
        }

        for(int i = 0; i < n; ++i){
            if(cur >= l){
                break; 
            }
            /*cout << "PREMOVE\n"; 
            if(i) cout << time << " " << i << " " << a[i-1] << " " << cur << " " << a[i] << "\n";
            else cout << time << " " << i << " " << cur << " " << a[i] << "\n";
            cout << "POST\n"; */
            if(a[i] < cur){
                //in time that has elapsed, move as close to cur as possible
                a[i] = min(cur, a[i] + time); 
                if(cur - a[i] <= k){
                    cur = a[i] + k; 
                    continue; 
                }
            }
            else{
                a[i] = max(cur, a[i] - time);
                if(a[i] == cur){
                    cur = a[i] + k; 
                    continue; 
                }
            }
            
            /*if(i) cout << time << " " << i << " " << a[i-1] << " " << cur << " " << a[i] << "\n";
            else cout << time << " " << i << " " << cur << " " << a[i] << "\n";*/
            
            //NOT AT CUR
            if(i){
                if(cur - a[i-1] - k < a[i] - cur){
                    
                    //scenario 1: move a[i-1] to cur - k, then meet in the middle
                    time += cur - k - a[i-1]; 
                    a[i] = a[i] - (cur - a[i-1] - k); 
                    //now, meet in the middle
                    time += a[i] - (a[i] + cur)/2.0; 
                    a[i] = (a[i] + cur)/2.0;
                    cur =  a[i] + k; 
                }
                else{
                    time += a[i] - cur; 
                    cur += k; 
                }
            }
            else{
                double req = a[i] - cur; 
                a[i] = cur; 
                time += req; 
                cur += k; 
                
            }
        }

        if(cur <= l){
            time += l - cur; 
        }
        //cout << cur << "\n";
        cout << (long long)(time * 2) << "\n"; 

    }
    return 0;
}