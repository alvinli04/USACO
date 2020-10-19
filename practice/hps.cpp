#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n; cin >> n;
	int h[n+1], p[n+1], s[n+1];
	h[0]=0, p[0]=0, s[0]=0;
	for(int i=1; i<=n; i++){
		char x; cin >> x;
		h[i] = h[i-1] + (x=='H');
		p[i] = p[i-1] + (x=='P');
		s[i] = s[i-1] + (x=='S');
	}
	int mx = 0;
	for(int i=0; i<=n; i++){
		mx = max({mx, h[i] + p[n]-p[i], p[i] + h[n]-h[i], h[i] + s[n]-s[i], s[i] + h[n]-h[i], s[i] + p[n]-p[i], p[i] + s[n]-s[i]});
	}
	cout << mx << '\n';
}
