/*
ID: ali201
LANG: C++
TASK: numtri
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("numtri.in");
	ofstream fout("numtri.out");
	int r; fin >> r;
	vector<vector<int>> nums(r), dp(r);
	for(int i=1; i<=r; i++){
		nums[i-1].assign(i, INT_MIN);
		for(int j=0; j<i; j++){
			fin >> nums[i-1][j];	
		}
	}
	dp[0].assign(1, nums[0][0]);
	for(int i=0; i<r-1; i++){
		dp[i+1].assign(i+2, INT_MIN);
		for(int j=0; j<i+1; j++){
			dp[i+1][j] = max(dp[i+1][j], dp[i][j] + nums[i+1][j]);
			dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + nums[i+1][j+1]);
		}
	}
	sort(dp[r-1].begin(), dp[r-1].end());
	fout << *dp[r-1].rbegin() << '\n';
}
