/*
ccc 04 s4 
ac, fun trying to figure out how to represnet orientation
*/

#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std; 

int tx, ty, tz, x, y, z, ans = 1e9, dst;
char cdir;  

int dir[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}; //fwd, lft, up

void invert(int a){
    for(int i = 0; i < 3; i++) dir[a][i] = -dir[a][i];
}

void sp(int a, int b){
    for(int i = 0; i < 3; i++) swap(dir[a][i], dir[b][i]);
}

void compute(int xs, int ys, int zs){
    int val = 0; 
    if(xs) val += abs(tx-x) * abs(tx-x);
    if(ys) val += abs(ty-y) * abs(ty-y);
    if(zs) val += abs(tz-z) * abs(tz-z);
    ans = min(ans, val);

}

int btw(int a, int b, int c){
    int ret = 1; if((a > c && c > b) || (b > c && c > a)) ret = 0;
    //if(ret == 0) printf("%d btw %d %d\n", c, a, b);
    return ret;
}

void turn(){
    if(cdir == 'U'){
        sp(0, 2);
        invert(2);
    }
    if(cdir == 'D'){
        sp(0, 2); 
        invert(0);
    }
    if(cdir == 'L'){
        sp(0, 1); 
        invert(1); 
    }
    if(cdir == 'R'){
        sp(0, 1); 
        invert(0);
    }
}

int main(){
    scanf("%d %d %d\n",&x, &y, &z);
    scanf("%d %d %d\n",&tx, &ty, &tz);

    compute(1,1,1);

    while(scanf("%d %c\n", &dst, &cdir)){
        int ox=x, oy=y, oz = z; 
        x += dst*dir[0][0]; y += dst*dir[0][1]; z+= dst*dir[0][2];
        compute(btw(x, ox, tx), btw(y, oy, ty), btw(z, oz, tz));
        //if(ans==1) printf("%d %d %d -> %d %d %d\n", ox, oy, oz, x, y, z); 
        if(cdir == 'E') break; 
        turn();
    }
    double out = pow((double)ans, (double)1/2); 
    printf("%.2lf\n", out); 
    return 0;
}