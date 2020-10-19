#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("measurement.in", "r", stdin);
	freopen("measurement.out", "w", stdout);
	int n,g; cin >> n >> g;
	vector<vector<int>> v(n, vector<int>(3));
	for(int i=0; i<n; i++){
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	sort(v.begin(), v.end());
	
	map<int,int> mp;
	multiset<int> vals;
	vals.insert(0);
	vals.insert(0);
	int ans=0;
	for(auto a : v){
		bool waslargest = false;
		if(mp[a[1]]==*vals.rbegin()) waslargest=true;
		if(waslargest){
			bool only = false;
			auto itr = vals.rbegin();
			++itr;
			if(*itr != mp[a[1]]) only=true;
			
			if(only){
				if(mp[a[1]]+a[2]<=*itr)
					++ans;
			} else {
				++ans;
			}
		} else {
			if(mp[a[1]]+a[2]>=*vals.rbegin())
				++ans;
		}
		if(mp[a[1]]) vals.erase(vals.find(mp[a[1]]));
		mp[a[1]]+=a[2];
		vals.insert(mp[a[1]]);
	}
	cout << ans << '\n';
}
