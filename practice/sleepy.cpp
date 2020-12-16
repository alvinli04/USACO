#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("sleepy.in", "r", stdin);
	freopen("sleepy.out", "w", stdout);
	int n; cin >> n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	//for(int i:arr)cout << i << ' ';
	int maxinv = -1;
	for(int i=1; i<n; i++){
		if(arr[i] < arr[i-1]) maxinv = i-1;
	}
	cout << maxinv+1 << '\n';
}
