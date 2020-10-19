#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

int main(){
	freopen("reststops.in", "r", stdin);
	freopen("reststops.out", "w", stdout);
	ll l,n,rf,rb; cin>>l>>n>>rf>>rb;
	vector<pii> stops(n); //tastiness, pos
	for(int i=0; i<n; i++){
		cin >> stops[i].second >> stops[i].first;
	}
	sort(stops.begin(), stops.end());
	pii last = make_pair(0,0);
	ll ans = 0;
	for(auto i=stops.rbegin(); i!=stops.rend(); i++){
		pii stop = *i;
		if(stop.second <= last.second) continue;
		int dist = stop.second - last.second;
		ll time = dist*(rf-rb);
		ans+=stop.first*time;
		last = stop;
	}
	cout << ans << '\n';
}
