//globex 2019 s1

#include <cstdio>
#include <map>

using namespace std; 

int main(){
    int n, k; 
    scanf("%d %d", &n, &k); 
    int total = 0; 
    map<int, int> planets; 
    while(n--){
        int t; 
        scanf("%d", &t); 
        if(planets.count(t) == 0){
            total++; 
            planets[t] = 0; 
        }
        printf("%d\n", planets[t]); 
        planets[t]++; 

    }
    printf("%d", total);

}