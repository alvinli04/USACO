#include <bits/stdc++.h>
using namespace std;

int n, k;

bool chck(int r, int* arr){
	int cnt = 0, curr = 0, kek = 0;
	while(curr < n){
		if(arr[curr] <= arr[cnt] + 2*r){
			++curr;
		} else{
			cnt = curr;
			++kek;
		}
	}
	if(cnt < curr)
		++kek;
	return kek <= k;
}

int main(){
	freopen("angry.in", "r", stdin);
	freopen("angry.out", "w", stdout);
	
	cin >> n >> k;
	int arr[n];
	for(int& i : arr) cin >> i;
	
	sort(arr, arr+n);
	
	int l=1, r=arr[n-1], ans;
	while(l <= r){
		int m = (l+r)/2;
		if(chck(m, arr)){
			ans = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	
	cout << ans;
}
