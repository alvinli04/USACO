#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("stacking.in", "r", stdin);
	freopen("stacking.out", "w", stdout);
	int n,k; cin >> n >> k;
	int difar[n+1];
	fill(difar, difar+n, 0);
	for(int i=0; i<k; i++){
		int a,b; cin >> a >> b;
		difar[a-1]++;
		difar[b]--;
	}
	int arr[n];
	int sum = 0;
	for(int i=0; i<n; i++){
		sum+=difar[i];
		arr[i] =sum;
	}
	sort(arr, arr+n);
	//for(int i:arr) cout << i << ' ';
	cout << arr[n/2] << '\n';
}
