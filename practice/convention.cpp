#include <bits/stdc++.h>
using namespace std;

int n,m,c;

bool chck(int* arr, int mid){
	int cnt = 0, curr = 0;
	for(int i=0; i<n; i++){
		if(arr[i] - arr[curr] > mid || i - curr + 1 > c || i == n-1){
			++cnt;
			curr = i;
		}
	}
	return cnt <= m;
}

int main(){
	//freopen("convention.in", "r", stdin);
	//freopen("convention.out", "w", stdout);
	
	cin >> n >> m >> c;
	
	int arr[n];
	for(int& i : arr) cin >> i;
	
	sort(arr, arr+n);
	
	int l=0, r=arr[n-1] - arr[0], ans;
	while(l<=r){
		int mid = (r+l)/2;
		if(chck(arr, mid)){
			r = mid-1;
			ans = mid;
		} else {
			l = mid+1;
		}
	}
	cout << chck(arr, 1);
	//cout << ans;	
}
