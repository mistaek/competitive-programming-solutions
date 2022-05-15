/*
ccc 07s1
ac
*/
#include <cstdio>

//feb 27, 2007
int main(){
    int tc; scanf("%d", &tc);
    while(tc--){
        int yy, mm, dd; scanf("%d %d %d", &yy, &mm, &dd);
        if(2007-yy > 18) printf("Yes\n");
        else if(2007 -yy < 18) printf("No\n");
        else{
            if(mm < 2) printf("Yes\n");
            else if(mm > 2) printf("No\n");
            else{
                if(dd <= 27) printf("Yes\n");
                else printf("No\n");
            }
        }
    }
    return 0;
}