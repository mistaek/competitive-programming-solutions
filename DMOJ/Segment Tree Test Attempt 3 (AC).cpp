#include <cstdio>
 

//ooOoO

using namespace std; 
// convenience functions and node struct
struct Node{int g, m, q;};
int left(int a){ return (a << 1); } int right(int a) { return  a << 1 | 1;} int mid(int a, int b){return (a+b)/2;}
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b);} int min(int a, int b){ return (a < b) ? a : b; }

//prototypes
void build(int a[], int pos, int l, int r); void update(int v, int l, int r, int pos, int val); void calc(int pos); 
int rmq(int v, int l, int r, int ql, int qr); int gcdq(int v, int l, int r, int ql, int qr); int fq(int v, int l, int r, int ql, int qr, int val);
// ok 
Node st[400001] = {}; 


int main(){
    int n, m; scanf("%d %d", &n, &m); 
    int a[n+1]; 
    for(int i = 0; i < n; i++) scanf(" %d", &a[i]); 

    build(a, 1, 0, n-1); 

    while(m--){
        char t; int n1, n2; scanf(" %c %d %d", &t, &n1, &n2); 
        if(t == 'C'){a[n1-1] = n2; update(1, 0, n-1, n1-1, n2);}
        else if(t == 'M'){printf("%d\n", rmq(1, 0, n-1, n1 -1, n2-1));}
        else if(t == 'Q'){printf("%d\n", fq(1, 0, n-1, n1-1, n2-1, gcdq(1, 0, n-1, n1-1, n2-1)));}
        else if(t == 'G'){printf("%d\n", gcdq(1, 0, n-1, n1-1, n2-1));}
    }
}

void build(int a[], int pos, int l, int r){
    if(l == r){ st[pos].g = a[r]; st[pos].m = a[r]; st[pos].q = 1;}
    else{
        int m = mid(l, r); 
        build(a, left(pos), l,m); 
        build(a, right(pos), m +1, r); 
        calc(pos); 
    }
}

void update(int v, int l, int r, int pos, int val){
    if(l == r){
        st[v].m = val; st[v].g = val; st[v].q = 1; return; 
    }
    int m = mid(l, r); 
    if(pos <= m) update(left(v), l, m, pos, val); 
    else if(pos > m) update(right(v), m+1, r, pos, val); 
    calc(v); 
    

}

void calc(int pos){
    st[pos].g = gcd(st[left(pos)].g, st[right(pos)].g); 
    st[pos].m = min(st[left(pos)].m, st[right(pos)].m);
    st[pos].q = 0; 
    if(st[pos].g == st[left(pos)].g) st[pos].q += st[left(pos)].q;  
    if(st[pos].g == st[right(pos)].g) st[pos].q += st[right(pos)].q;  
}

int rmq(int v, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return -1; 
    if(l >= ql && r <= qr) return st[v].m; 

    int p1 = rmq(left(v), l, mid(l, r), ql, qr); 
    int p2 = rmq(right(v), mid(l, r) +1, r,  ql, qr); 
    if(p1 == -1) return p2; 
    if(p2 == -1) return p1; 
    return min(p2, p1); 
}

int gcdq(int v, int l, int r, int ql, int qr){
    if(l > qr || r < ql) return -1; 
    if(l >= ql && r <= qr) return st[v].g;

    int p1 = gcdq(left(v), l, mid(l, r), ql, qr); 
    int p2 = gcdq(right(v), mid(l, r) +1, r,  ql, qr); 
    if(p1 == -1) return p2; 
    if(p2 == -1) return p1;
    return gcd(p1, p2); 
}

int fq(int v, int l, int r, int ql, int qr, int val){
    if(l > qr || r < ql) return -1; 
    if(l >= ql && r <= qr) return (st[v].g == val) ? st[v].q : 0; 

    int p1 = fq(left(v), l, mid(l, r), ql, qr, val); 
    int p2 = fq(right(v), mid(l, r) +1, r, ql, qr, val); 
    
    if(p1 == -1) return p2; 
    if(p2 == -1) return p1;

    return p1 + p2; 

}