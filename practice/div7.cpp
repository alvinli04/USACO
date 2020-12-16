#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("div7.in", "r", stdin);
	freopen("div7.out", "w", stdout);
	int n; cin >> n;
	int arr[n+1];
	arr[0] = 0;
	map<int,int> fl, fr;
	for(int i=1; i<=n; i++){
		int x; cin >> x;
		arr[i] = (arr[i-1] + x)%7;
		//update maps
		if(!fl[arr[i]]) fl[arr[i]] = i;
		else fl[arr[i]] = min(fl[arr[i]], i);
		if(!fr[arr[i]]) fr[arr[i]] = i;
		else fr[arr[i]] = max(fr[arr[i]], i);
	}
	int mx = 0;
	for(int i=0; i<7; i++){
		mx = max(mx, fr[i] - fl[i]);
	}
	cout << mx << '\n';
}
