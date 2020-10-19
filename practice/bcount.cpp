#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);
	int n,q; cin >> n >> q;
	int h[n+1], g[n+1], j[n+1];
	h[0]=0, g[0]=0, j[0]=0;
	for(int i=1; i<=n; i++){
		int x; cin >> x;
		h[i] = h[i-1] + (x==1);
		g[i] = g[i-1] + (x==2);
		j[i] = j[i-1] + (x==3);
	}
	for(int i=0; i<q; i++){
		int a,b; cin >> a >> b;
		cout << h[b]-h[a-1] << ' ' << g[b]-g[a-1] << ' ' << j[b]-j[a-1] << '\n';
	}
}
