#include <bits/stdc++.h>
using namespace std;

int main(){
//	freopen("diamond.in", "r", stdin);
//	freopen("diamond.out", "w", stdout);
	
	int  n,k; cin >> n >> k;
	
	vector<int> arr(n);
	for(auto& i : arr) cin >> i;
	
	sort(arr.begin(), arr.end());
	int lmx[n], rmx[n+1];
	fill(lmx, lmx+n, 0);
	fill(rmx, rmx+n, 0);
	for(int  i=0; i<n; i++){
		auto itr1 = lower_bound(arr.begin(), arr.end(), arr[i]-k);
		lmx[i]=max(lmx[i-1], i + 1 - (int)(itr1 - arr.begin()));
	}
	rmx[n] = 0;
	for(int  i=n-1; i>=0; i--){
		auto itr = lower_bound(arr.begin(), arr.end(), arr[i]+k);
		if(*itr != arr[i]+k) itr--;
		rmx[i]=max(rmx[i+1], (int)(itr - arr.begin()) - i + 1);
	}
	int mx = rmx[0];
	for(int i=0; i<n-1; i++){
		mx = max(mx, lmx[i]+rmx[i+1]);
	}
	cout << mx << '\n';
}
