#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	freopen("haybales.in", "r", stdin);
	freopen("haybales.out", "w", stdout);
	int n,q; cin >> n >> q;
	vector<ll> hay(n);
	for(int i=0; i<n; i++){
		cin >> hay[i];
	}
	sort(hay.begin(), hay.end());
	while(q--){
		ll a,b; cin >> a >> b;
		cout << upper_bound(hay.begin(), hay.end(), b) - lower_bound(hay.begin(), hay.end(), a) << '\n';
	}
}
