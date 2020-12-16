#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int64_t, int64_t> a, pair<int64_t, int64_t> b){
	if(a.second - a.first == b.second - b.first){
		return a.second + a.first > b.second + b.first;
	}
	return a.second - a.first > b.second - b.first;
}

int main(){
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	int n; cin >> n;
	pair<int64_t, int64_t> arr[n]; //x,y
	for(int i=0; i<n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr+n, cmp);
	//for(auto i:arr) cout << i.first << ' ';
	int ans = 1;
	int64_t bigsum = arr[0].first + arr[0].second;
	for(int i=1; i<n; i++){
		if(arr[i].first + arr[i].second > bigsum){
			++ans;
			bigsum = arr[i].first + arr[i].second;
		}
	}		
	cout << ans << '\n';
}
