#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("pairup.in", "r", stdin);
	freopen("pairup.out", "w", stdout);
	
	int n; cin >> n;
	pair<int,int> arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i].second >> arr[i].first; //output, number
	}
	sort(arr, arr+n);
	int mx = 0;
	int l = 0, r = n-1;
	while(l <= r){
		mx = max(mx, arr[l].first + arr[r].first);
		if(r==l){
			break;
		} else {
			int mn = min(arr[l].second, arr[r].second);
			arr[l].second -= mn;
			arr[r].second -= mn;
		}
		if(arr[l].second == 0) l++;
		if(arr[r].second == 0) r--;
	}
	cout << mx << '\n';
}
