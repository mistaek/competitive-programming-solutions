/*
1676H
AC: vector initialization is O(n)? 
*/

#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>

using namespace std; 

long long merge(vector<int> &a, vector<int> &temp, int left, int mid, int right){

    long long res = 0; 
    int i = left, j = mid+1, k = left; 
    while(k != right + 1){
        if(j > right){
            temp[k++] = a[i++]; 
        }
        else if(i > mid){
            temp[k++] = a[j++]; 
        }
        else if(a[i] <= a[j]){
            temp[k++] = a[i++]; 
        }
        else if(a[j] < a[i]){
            res += mid - i + 1; 
            temp[k++] = a[j++];
        }
    }
    for(k = left; k <= right; k++){
        a[k] = temp[k]; 
    }
    return res; 
}

long long msort(vector<int> &a,vector<int> &temp, int left, int right){
    long long res = 0; 

    if(left != right){
        int mid = (left + right)/2; 
        res += msort(a, temp, left, mid); 
        res += msort(a, temp, mid+1, right); 
        res += merge(a, temp, left, mid, right); 
    }
    return res; 
}

int main(){
    int t; scanf("%d", &t); 
    while(t--){
        int n; scanf("%d", &n); 

        vector<int> a(n), temp(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        
        long long res = msort(a, temp, 0, n-1); 
        long long curl = 1; 
        for(int i = 1; i < n; i++){
            if(a[i] != a[i-1]){
                res += (curl * (curl-1))/2;
                curl = 1; 
            }
            else curl++;
        }
        res += (curl * (curl-1))/2;

        printf("%lld\n", res); 
        
        
    }
    return 0;
}