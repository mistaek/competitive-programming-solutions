// works :)
#include <cstdio>
#include <list>

using namespace std; 

int main(){
    int nf; 
    scanf("%d", &nf); 
    list<int> friends; 
    for(int i = 1; i <=nf; i++) friends.push_back(i); 
    int r; 
    scanf("%d", &r); 
    while(r--){
        int a; 
        scanf("%d", &a); 
        list<int>::iterator it; 
        it = friends.begin(); 
        advance(it, a-1); 
        int c = nf/a; 
        nf-=c; 
        while(c--){
            it = friends.erase(it); 
            advance(it, a-1); 
        }
    }
    for(auto p = friends.begin(); p!= friends.end(); p++) printf("%d\n", *p);
    return 0;
}