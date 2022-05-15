//dmopc p0
#include <cstdio> 

int main(){
    int num; 
    scanf("%d", &num); 
    while(num--){
        int seq[10];
        bool isntA = false, isntG = false;
        for(int i = 0; i < 10; i++) scanf("%d", &seq[i]); 
        for(int i = 0; i < 8; i++){
            if(seq[i] + seq[i+2] != 2*seq[i+1]) isntA = true; 
            if(seq[i]*seq[i+2] != seq[i+1]*seq[i+1]) isntG = true;
        }
        if(!isntA && !isntG){
            printf("both\n");
        }
        else if(!isntA) printf("arithmetic\n"); 
        else if(!isntG) printf("geometric\n"); 
        else printf("neither\n"); 
    }
    return 0; 
}