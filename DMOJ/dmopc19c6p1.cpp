/*
dmopc19c6p1
ray
wipwip
*/

#include <cstdio>
//do later
int main(){
    //y = mx+b
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
    double m1; 
    if(x1 == x2 )m1 = -1; 
    else m1 = (y2-y1)/(x2-x1);
    double b1 =  y2 - (m1*x2); 
    int x3, y3, x4, y4;
    scanf("%d %d %d %d", &x3, &y3, &x4, &y4); 
    double m2; 
    if(x3 == x4 )m2 = -1; 
    else m2 = (y3-y4)/(x3-x4);
    double b2 =  y4 - (m2*x2); 

    if(m1 == m2){
        if(b1 ==b2) printf("coincident");
        else printf("parallel");
    }
    else{
        double xo;
        if(m1 == -1) xo = x1;
        else if(m2 == -1) xo = x3;  
        else xo = (b2 -b1)/(m2-m1); 
        double yo;
        if(m1 == -1) yo = y4;
        else if(m2 == -1) yo = y2;
        else yo = (m1*xo) + b1; 
        printf("%.6lf %.6lf", xo, yo);
    }
    return 0;
}