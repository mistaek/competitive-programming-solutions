/*
1629D
solved this way too slow
*/

#include <cstdio>
#include <string>
#include <iostream>
using namespace std;



int main(){
    int tc; cin >> tc; 
    while(tc--){
        int present[27][27][27] = {}, n; cin >> n;
        bool t = false;
        for(int i = 0; i < n; i++){
            string in; 
            cin>> in;
            bool a = true;
            for(int i = 0; i < in.length(); i++){
                if(in[i] != in[in.length() - i - 1]){ a = false; break;}
            }
            if(a) t = true;
            
            if(in.length() == 1){
                t = true; 
            }
            else if(in.length() == 2){
                for(int i = 0; i < 27; i++){ 
                    if(present[i][in[0] - 'a'][in[1] - 'a']) t = true;
                }
                present[26][in[1] - 'a'][in[0] - 'a'] = 1;
                //printf("%d %d %d\n", 26, in[1]-'a', in[0] - 'a');
            }
            else if(in.length() == 3){
                if(present[in[0] - 'a'][in[1]- 'a'][in[2] - 'a'] || present[26][in[1] - 'a'][in[2] - 'a']) t = true;
                present[in[2] - 'a'][in[1] - 'a'][in[0] - 'a'] = 1;
                //printf("%d %d %d\n", in[2] - 'a', in[1]-'a', in[0] - 'a');
            } 
        }
        if(t) printf("YES\n"); 
        else printf("NO\n");
    }
    return 0;
}