#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("taming.in", "r", stdin);
	freopen("taming.out", "w", stdout);
	int n; cin >> n;
	int mn[n], mx[n], log[n];
	for(int i=0; i<n; i++){
		cin >> log[i];
	}
	if(log[0]>0){
		cout << -1 << '\n';
		return 0;
	}
	log[0] = 0, mn[n-1] = INT_MAX, mx[n-1] = 0;
	for(int i=n-1; i>=0; i--){
		if(log[i]!=-1){
			mn[i] = log[i];
			mx[i] = log[i];
		} else{
			//min
			if(mn[i+1] != 0) mn[i] = mn[i+1]-1;
			else mn[i] = INT_MAX;
			//max
			if(mx[i+1] != 0) mx[i] = mn[i+1]-1;
			else mx[i] = 0;
		}
		if(i < n-1 && mx[i+1]!=0 && mx[i]!=mx[i+1]-1){
			cout << -1 << '\n';
			return 0;
		}
	}
	int mnz = 0, mxz = 0;
	for(int i=0; i<n; i++){
		if(mn[i] == 0) ++mnz;
		if(mx[i] == 0) ++mxz;
	}
	cout << mnz << ' ' << mxz << '\n';
}
