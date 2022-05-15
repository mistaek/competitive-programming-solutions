#include <cstdio>
#include <vector>

using namespace std; 

int main(){
    int prefx[200000] = {}, n; 
    scanf("%d", &n); 
    for(int i = 0; i < n; i++){
        int num; 
        scanf("%d", &num); 
        prefx[num+100000]++; 
    }
    int best = 0;
    vector<int> modes; 
    for(int i =0; i <200000; i++){
        if(prefx[i] > best){
            best = prefx[i]; 
            modes.clear(); 
            modes.push_back(i-100000); 
        }
        else if(prefx[i] == best) modes.push_back(i -100000); 
    }
    for(vector<int>::iterator it = modes.begin(); it!=modes.end(); it++){
        if(it!= modes.begin()) printf(" "); 
        printf("%d", *it);
    }

    return 0; 
}