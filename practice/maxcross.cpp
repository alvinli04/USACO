#include <bits/stdc++.h>
using namespace std;

int n,k,b;

bool check(int m, int* arr){
	int mx = INT_MAX;
	for(int i=k; i<n+1; i++){
		mx = min(mx, arr[i] - arr[i-k]);
	}
	return mx <= m;
}

int main(){
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	cin >> n >> k >> b;
	int arr[n+1];
	memset(arr, 0, sizeof(arr));
	for(int i=0; i<b; i++){
		int a; cin >> a;
		arr[a] = 1;
	}
	
	for(int i=1; i<n+1; i++){
		arr[i] = arr[i] + arr[i-1];
	}
	
	int l=0, r=n, ans;
	while(l<=r){
		int m = (l+r)/2;
		if(check(m, arr)){
			ans = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	
	cout << ans;
}
