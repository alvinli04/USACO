#include <bits/stdc++.h>
using namespace std;

typedef pair<int64_t,int64_t> pii;
typedef map<int64_t,int64_t> mii;

bool cmp(pii a, pii b){
	return a.second < b.second;
}

int main(){
	freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	int n; cin >> n;
	pii arr[n];
	mii mxx, mxy, mnx, mny, rmxx, rmxy, rmnx, rmny;
	int64_t max_x, max_y, min_x, min_y;
	for(int i=0; i<n; i++){
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr+n);
	int64_t mx = 0, mn = LLONG_MAX;
	for(auto i:arr){
		mx = max(mx, i.second);
		mn = min(mn, i.second);
		mxy[i.first] = mx;
		mny[i.first] = mn;
	}
	max_y = mxy[arr[n-1].first], min_y = mny[arr[n-1].first];
	reverse(arr, arr+n);
	mx = 0, mn = LLONG_MAX;
	for(auto i:arr){
		mx = max(mx, i.second);
		mn = min(mn, i.second);
		rmxy[i.first] = mx;
		rmny[i.first] = mn;
	}
	
	sort(arr, arr+n, cmp);
	mx = 0, mn = LLONG_MAX;
	for(auto i:arr){
		mx = max(mx, i.first);
		mn = min(mn, i.first);
		mxx[i.second] = mx;
		mnx[i.second] = mn;
	}
	max_x = mxx[arr[n-1].second], min_x = mnx[arr[n-1].second];
	reverse(arr, arr+n);
	mx = 0, mn = LLONG_MAX;
	for(auto i:arr){
		mx = max(mx, i.first);
		mn = min(mn, i.first);
		rmxx[i.second] = mx;
		rmnx[i.second] = mn;
	}
	int64_t area = (max_x - min_x)*(max_y - min_y);
	int64_t A = area;
	sort(arr, arr+n);
	for(int i=0; i<n-1; i++){
		int64_t tmp = (arr[i].first - min_x)*(mxy[arr[i].first] - mny[arr[i].first]) + (max_x - arr[i+1].first)*(rmxy[arr[i+1].first] - rmny[arr[i+1].first]);
		area = min(area, tmp);
	}
	sort(arr, arr+n, cmp);
	for(int i=0; i<n-1; i++){
		int64_t tmp = (arr[i].second - min_y)*(mxx[arr[i].second] - mnx[arr[i].second]) + (max_y - arr[i+1].second)*(rmxx[arr[i+1].second] - rmnx[arr[i+1].second]);
		area = min(area, tmp);
	}
	cout << A - area << '\n';
}




















