#include <bits/stdc++.h>
using namespace std;

bool cmp(vector<int64_t> a, vector<int64_t> b){
	return a[2] > b[2];
}

int main(){
	int n,m; cin >> n >> m;
	int cows[n];
	for(int i=0; i<n; i++){
		cin >> cows[i];
	}
	set<int> wrong;
	map<int,bool> taken;
	for(int i=0; i<n; i++){
		if(cows[i]!=i+1) wrong.insert(i+1);
	}
	int sz = wrong.size();
	if(!wrong.size()){
		cout << -1 << '\n';
		return 0;
	}
	vector<vector<int64_t>> wh(m, vector<int64_t>(3));
	for(int i=0; i<m; i++){
		cin >> wh[i][0] >> wh[i][1] >> wh[i][2];
	}
	sort(begin(wh), end(wh), cmp);
	for(auto a : wh){
		if(wrong.find(a[0])!=wrong.end() && wrong.find(a[1])!=wrong.end()){
			if(!taken[a[0]]){
				taken[a[0]] = true;
				--sz;
			}
			if(!taken[a[1]]){
				taken[a[1]] = true;
				--sz;
			}
			if(sz==0){
				cout << a[2] << '\n';
				return 0;
			}
		}
	}
}
