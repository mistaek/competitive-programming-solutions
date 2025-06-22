/*
1225D
*/

#include <iostream>
#include <vector>

using namespace std; 

vector<bool> isPrime(1e5+1, true);
vector<long long> complement(1e5+1, 1); 
vector<long long> cnt(1e5+1, 0); 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);

    int n, k; cin >> n >> k;
    for(int i = 0; i < n; ++i){
        int a; cin >> a; 
        cnt[a]++;
    }

    isPrime[0] = false; 
    isPrime[1] = false;  
    // n log log n
    for(long long i = 2; i <= 1e5; ++i){
        if(isPrime[i]){
            for(long long j = i; j <= 1e5; j += i){
                if(j > i) isPrime[j] = false; 
                if(cnt[j] == 0 || complement[j] == -1) continue; //don't bother
                int num = j, pcnt = 0;
                while(num % i == 0){
                    num /= i; ++pcnt; 
                }
                pcnt %= k; 
                for(int looper = 0; looper < (k - pcnt) % k; ++looper){
                    complement[j] *= i;
                    if(complement[j] > 1e5){
                        complement[j] = -1; break;
                    }
                }
            }
        }
    }

    long long ans = 0;
    for(int i = 1; i <= 1e5; ++i){
        if(cnt[i] && complement[i] != -1){
            //cout << "TESTING " << i << " " << complement[i] << "\n";
            for(int j = 1; j <= 1e5; ++j){
                long long val = complement[i];
                for(int looper = 0; looper < k; ++looper){ // get to j^k
                    val *= j; 
                    if(val > 1e5){val = 0; break; }
                }
                if(val == 0) break; 
                //cout << "POSSIBLE PARTNER " << val << "\n";
                if(val == i){
                    ans += (cnt[i] * (cnt[i]-1));
                    
                }
                else ans += cnt[i] *cnt[val];
            }
        }
    }
    cout << ans/ 2 << "\n";
    

    

    
    return 0;
}