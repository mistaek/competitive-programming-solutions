#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std; 

int main(){
    int tc; cin >> tc; 
    while(tc--){
	int n; cin >> n; 
	vector<pair<double, double>> points; 
	for(int i = 0; i < n; ++i){
		long long x, y; 
		cin >> x >> y; 
		double r = sqrt((x * x) + (y * y));
		double theta; 
		if(x == 0 && y > 0) theta = M_PI/2.0; 
		else if (x == 0 && y < 0) theta = 3.0*M_PI/2.0; 
		else if(x < 0){
			theta = M_PI + atan((double)y/x); 
		}
		else theta = atan((double) y/x); 
        
		points.push_back({theta, r}); 
        //cout << r << " " << theta << "\n";
        //cout << r * cos(theta) << " " << points[i].second * sin(points[i].first) << "\n";

	}

	sort(points.begin(), points.end()); 
	
	for(int i = 0; i < n; ++i){
		points.push_back({points[i].first + 2*M_PI, points[i].second}); 
	}

	int ans = n; 
	for(int i = 0; i < n; ++i){
		auto it = upper_bound(points.begin(), points.end(), make_pair((double)points[i].first + M_PI, 0.0)); 
		int j = it - points.begin(); 
        //cout << i << " " << j << "\n";
		ans = min(ans, (int) j - i - 1); 
		ans = min(ans, n-j + i + 1);
	}

	cout << ans << "\n"; 
    }
	return 0;
}