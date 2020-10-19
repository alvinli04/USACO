#include <bits/stdc++.h>
using namespace std;

const int64_t mod = 1e9+7;

int main(){
	freopen("triangles.in", "r", stdin);
	freopen("triangles.out", "w", stdout);
	
	int n; cin >> n;
	map<int64_t,vector<int64_t>> mpx, mpy;
	map<pair<int64_t,int64_t>, int64_t> valx, valy;
	vector<pair<int64_t,int64_t>> points(n);
	for(int i=0; i<n; i++){
		cin >> points[i].first >> points[i].second;
	}
	for(auto a: points){
		mpx[a.first].push_back(a.second);
		mpy[a.second].push_back(a.first);
	}
	for(auto a : mpx){
		sort(a.second.begin(), a.second.end());
		//calc first
		for(int i=1; i<a.second.size(); i++){
			valx[{a.first, a.second[0]}] += a.second[i]-a.second[0];
		}
		for(int i=1; i<a.second.size(); i++){
			valx[{a.first, a.second[i]}] = (valx[{a.first, a.second[i-1]}] + (2*i - a.second.size())*(a.second[i]-a.second[i-1]))%mod;
		}
	}
	for(auto a : mpy){
		sort(a.second.begin(), a.second.end());
		for(int i=1; i<a.second.size(); i++){
			valy[{a.second[0], a.first}] += a.second[i]-a.second[0];
		}
		for(int i=1; i<a.second.size(); i++){
			valy[{a.second[i], a.first}] = (valy[{a.second[i-1], a.first}] + (2*i - a.second.size())*(a.second[i]-a.second[i-1]))%mod;
		}
	}
	
	int64_t ans = 0;
	for(auto p : points){
		(ans+=(valx[{p.first, p.second}] * valy[{p.first, p.second}]))%=mod;
	}
	//cout << valx[{1,2}];
	cout << ans << '\n';
}
