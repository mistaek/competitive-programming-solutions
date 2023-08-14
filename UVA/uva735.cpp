#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std; 
int main(){
    char stars[70]; 
    memset(stars, '*', sizeof(stars)); 
    int pts; 
   
    while(scanf("%d", &pts), pts > 0){
        if(pts > 180 ){ printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n%s\n", pts, stars); continue;}
        int c = 0, p = 0; 
        for(int i = 0; i <= 60; i++){
            if(i % 2 && i % 3 && i > 20) continue; 
            if(i % 3 && i % 2 == 0 &&i/2 > 20 && i != 50) continue;
            for(int j = 0; j <= 60; j++){
                if(j %2 && j % 3 && j > 20)continue; 
                if(j % 3 && j % 2 == 0 &&j/2 > 20 && j != 50) continue;
                int third = pts - i - j; 
                if(third > 20 && third%3  && third %2) continue; 
                if(third % 3 && third % 2 == 0 &&third/2 > 20 && third != 50) continue; 
                if(third < 0 || third > 60) continue; 
                p++; 
                if(third >= j && j >= i) {c++; 
                	//printf("%d %d %d\n", i, j, third);
                	
                } 
            }
        }
        if(p)printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\nNUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n%s\n", pts, c, pts, p, stars); 
        else printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n%s\n", pts, stars);
    }
    printf("END OF OUTPUT\n");
    return 0; 
}