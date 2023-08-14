/*
1846F
AC
*/
 
#include <iostream>
#include <algorithm>
using namespace std; 
 
int main(){
    int t; cin >> t; 
    while(t--){
        int n; cin >> n; 
        int cnt[10] = {}, pcnt[10] = {}, a[n];
        int gen = 0;
        while(true){
            int g = -1;
            bool guess = false; 

            for(int i = 0; i <10 ;i++) cnt[i] = 0;
            for(int i = 0; i < n; i++){
                cin >> a[i];
                if(a[i] < 10 && a[i] >= 0) cnt[a[i]]++; 
                else{
                    g = a[i];
                    guess = true; 
                }
            }
            if(gen){
                for(int i = 0; i < 10; i++){
                    if(pcnt[i] == cnt[i] -1){
                        g = i; 
                        guess = true; 
                    }
                }
            }
            for(int i = 0; i < 10; i++) pcnt[i] = cnt[i];
            gen++;
            if(!guess){
                cout << "- 0" << endl; 
            }
            else{

                if(n == 1){
                    cout << "! 1" << endl; 
                    break;
                }
                else if(g >= 10 || g < 0){
                    for(int i = 0; i < n; i++){
                        if(a[i] == g) cout << "! " << i + 1 << endl; 
                    }
                    break; 
                }
                else if(cnt[g] == 1){
                    for(int i = 0; i < n; i++){
                        if(a[i] == g) cout << "! " << i + 1 << endl; 
                    }
                    break; 
                }
                else if(gen == 5){
                    cout << "! 1" << endl; 
                    break;
                }
                else{
                    cout << "- " << n - cnt[g]; 
                    for(int i = 0; i < n; i++){
                        if(a[i] != g) cout << " " << i+1; 
                    }
                    cout << endl;
                    for(int i = 0; i < 10; i++){
                        if(i != g) pcnt[i] = 0;
                    }
                    n = cnt[g];
                }
            }
            cout.flush();
        }
    }
    return 0;
}