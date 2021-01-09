#include <bits/stdc++.h>
using namespace std;

int n,k,b;

bool chck(int m, int* arr){
	int bask = 0;
	for(int i=0; i<k; i++){
		bask += arr[i]/m;
	}
	//cout << m << ' ' << bask << '\n';
	return bask <= k;
}

int main(){
	//freopen("berries.in", "r", stdin);
	//freopen("berries.out", "w", stdout);
	
	cin >> n >> k;
	int arr[n];
	for(int& i : arr) cin >> i;
	
	sort(arr, arr+n, greater<int>());
	int sum = 0;
	for(int i: arr) sum += i;
	
	//each basket has at least b berries
	int l = 0, r = sum;
	while(l<=r){
		int m = (l+r)/2;
		if(chck(m, arr)){
			b = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	
	
}
