#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

vector<pll> intervals;
int n,m;

bool works(ll dist){
	int curr_int = 0;
	ll curr_num = intervals[0].first;
	int cows_left = n-1;
	while(cows_left){
		if(curr_num + dist <= intervals[curr_int].second){
			curr_num += dist;
		} else {
			++curr_int;
			while(curr_int < m && curr_num + dist > intervals[curr_int].second){
				++curr_int;
			}
			if(curr_int == m) return false;
			curr_num = max(curr_num + dist, intervals[curr_int].first);
		}
		--cows_left;
	}
	return true;
}

int main(){
	freopen("socdist.in", "r", stdin);
	freopen("socdist.out", "w", stdout);
	cin >> n >> m;
	ll a,b;
	for(int i=0; i<m; i++){
		cin >> a >> b;
		intervals.push_back(make_pair(a,b));
	}
	sort(intervals.begin(), intervals.end());
	//binary search
	ll l=0, r=intervals[m-1].second;
	ll ans;
	while(l<=r){
		ll m = (r+l)/2;
		if(works(m)){
			ans = m;
			l = m+1;
		} else{
			r = m-1;
		}
	}
	cout << ans << '\n';
}
