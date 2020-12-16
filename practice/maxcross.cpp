#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int n,k,b; cin >> n >> k >> b;
	multiset<int> broken, highest;
	for(int i=0; i<b; i++){
		int x; cin >> x;
		broken.insert(x);
	}
	int lights[n+1];
	lights[0]=0;
	for(int i=1; i<=n; i++){
		lights[i] = lights[i-1] + (broken.find(i)!=broken.end());
	}
	int mn = INT_MAX;
	for(int i=k; i<=n; i++){
		mn = min(mn, lights[i]-lights[i-k]);
	}
	cout << mn << '\n';
}
