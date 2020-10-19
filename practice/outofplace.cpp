#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("outofplace.in", "r", stdin);
	freopen("outofplace.out", "w", stdout);
	int n; cin >> n;
	int arr[n], sorted[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		sorted[i] = arr[i];
	}
	sort(sorted, sorted+n);
	int s = -1;
	for(int i=0; i<n; i++){
		if(sorted[i]!=arr[i]) ++s;
	}
	s = max(s, 0);
	cout << s << '\n';
}
