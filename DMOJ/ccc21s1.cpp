/*
ccc 21 s1
ac
*/
#include <cstdio>
#include <algorithm>

using namespace std; 
int heights[10001], widths[10001], diff[10001], mini[10001];
double ans = 0;
int main(){
    int n; scanf("%d", &n);
    for(int i = 0; i <= n; i++){
        scanf("%d", &heights[i]); 
        if(i) diff[i] = abs(heights[i] - heights[i-1]); 
        if(i) mini[i] = min(heights[i], heights[i-1]);
    }
    for(int i = 0; i < n; i++){
        scanf("%d", &widths[i]);
    }
    for(int i = 1; i <= n; i++){
        ans += mini[i] * widths[i-1];
        ans += (double) diff[i] * widths[i-1] /2; 
    }
    printf("%lf", ans);
    return 0;
}

/*
eric's
#include <bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    double area = 0;
    cin >> n;
    int ar[n + 1], h[n];
    for (int i = 0; i <= n; i++)
        cin >> ar[i];
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < n; i++)
        area += (ar[i] + ar[i + 1]) * h[i];
    cout << area / 2 << '\n';
    return 0;
}
*/
