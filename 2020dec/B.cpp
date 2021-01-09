#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back

int psums[2502][2502];

int query(int uy, int dy, int lx, int rx){
	return psums[dy][rx] + psums[uy-1][lx-1] - psums[dy][lx-1] - psums[uy-1][rx];
}

int main(){
	
	int n; cin >> n;
	pii points[n];
	int x[n], y[n];
	map<int,int> cmpx, cmpy;
	
	for(int i=0; i<n; i++){
		cin >> points[i].first >> points[i].second;
		y[i] = points[i].first;
		x[i] = points[i].second;
	}	
	
	sort(x, x+n);
	sort(y, y+n);
	
	for(int i=0; i<n; i++){
		cmpx[x[i]] = i+1;
		cmpy[y[i]] = i+1;
	}
	
	for(auto& p : points){
		p.first = cmpy[p.first], p.second = cmpx[p.second];
		psums[p.first][p.second] = 1;
	}

	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			psums[i][j] += psums[i-1][j] + psums[i][j-1] - psums[i-1][j-1];
		}
	}
	
	ll ans = 0;
	
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int dy = max(points[i].first, points[j].first);
			int uy = min(points[i].first, points[j].first);
			int rx = max(points[i].second, points[j].second);
			int lx = min(points[i].second, points[j].second);
			ans += query(1, uy, lx, rx) * query(dy, n, lx, rx);
		}
	}
	
	cout << ans + 1 << '\n';
}

