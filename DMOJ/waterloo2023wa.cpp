#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main(){
	int t; cin >> t; 
	while(t--){
		int n; cin >> n; 
		vector<vector<int>> h(n, vector<int>(n)); 
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < n; ++j){
				cin >> h[i][j];
			}
		}

		vector<int> path; 
		int down = 0, up = 0; 
		for(int i = 0; i < n; ++i){
			if(i % 2 == 0){
				for(int j = 0; j < n; j++) path.push_back(h[i][j]); 
			}
			else{
				for(int j = n-1; j >= 0; j--) path.push_back(h[i][j]); 
			}
		}

		for(int i = 1; i < n * n; ++i){
			if(path[i] < path[i-1]) ++down; 
			else ++up; 
		}

		if(up > down) reverse(path.begin(), path.end()); 
		
		for(int i = 0; i < n * n; ++i){
			if(i) cout << " "; 
			cout << path[i]; 
		}
		cout << "\n";
	}
	return 0;
}