#include <bits/stdc++.h>
using namespace std;

bool good(int m, int* cities, int* towers){
	
}

int main(){
	int n,m; cin >> n >> m;
	int cities[n];
	int towers[m];
	for(int& i : cities) cin >> i;
	for(int& i : towers) cin >> i;
	int l=0, r=2e9, ans;
	while(l<=r){
		int m = (l+r)/2;
		if(good(m, cities, towers)){
			ans = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << ans;
}
