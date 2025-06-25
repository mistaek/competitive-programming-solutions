/*
1163A
*/

#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <numeric>

using namespace std; 

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0); 
    long long n; cin >> n; 

    vector<pair<long long, long long>> pts(n); 
    for(long long i = 0; i < n; ++i){
        cin >> pts[i].first >> pts[i].second; 
    }

    set<pair<pair<long long, long long>, pair<long long, long long>>> appeared; // whether or not a line has appeared
    map<pair<long long, long long>, long long> slopeCount; //count number of different lines which have the same slope
    long long ans = 0;
    //compute lines
    for(long long i = 0; i < n; ++i){
        for(long long j = i+1; j < n; ++j){
            long long xdelta = pts[j].first - pts[i].first, ydelta = pts[j].second - pts[i].second; 
            pair<pair<long long, long long>, pair<long long, long long>> line; //store everything as simplified fractions
            if(xdelta == 0){
                //vertical line
                line = {{0, 1}, {pts[i].first, 1}}; 
            }
            else if(ydelta == 0){
                line = {{1, 0}, {pts[i].second, 1}};
            }
            else{
                long long gcdd = gcd(ydelta, xdelta);
                xdelta /= gcdd; ydelta /= gcdd;
                if(xdelta < 0){
                    xdelta *= -1; 
                    ydelta *= -1;
                }
                long long yceptN = pts[i].second * xdelta - ydelta * pts[i].first, yceptD = xdelta; 
                gcdd = gcd(yceptN, yceptD); 
                yceptN /= gcdd; yceptD /= gcdd; 
                if(yceptN == 0) yceptD = 1;
                if(yceptD < 0){
                    // for consistency, always have positive denominator
                    yceptD *= -1; 
                    yceptN *= -1; 
                }
                line = {{ydelta, xdelta}, {yceptN, yceptD}}; 
            }

            if(appeared.find(line) != appeared.end()){
                continue; 
            }
            appeared.insert(line); 
            slopeCount[line.first]++; 
        }
    }
    long long numLines = (long long)appeared.size(); 
    for(auto& [k, v] : slopeCount){
        ans += v * (numLines -v);
    }


    ans /=2; 
    cout << ans << "\n";
    return 0;
}