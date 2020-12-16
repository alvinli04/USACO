#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("lifeguards.in", "r", stdin);
	freopen("lifeguards.out", "w", stdout);
	int n; cin >> n;
	vector<pair<int,int>> times(2*n);
	vector<int> alone(n, 0);
	set<int> present;
	map<int,int> mp;
	int t=0, mn = INT_MAX;
	for(int i=0; i<n; i++){
		int a,b; cin >> a >> b;
		times[2*i] = {a,i};
		times[2*i+1] = {b,i};
	}
	sort(begin(times), end(times));
	int last = 0;
	for(auto a : times){
		if(present.size()==1){
			alone[*begin(present)]+=(a.first - last);
		}
		if(present.size()){
			t += (a.first - last);
		}
		auto itr = present.find(a.second);
		if(itr == present.end()){
			present.insert(a.second);
		} else {
			present.erase(present.find(a.second));
		}
		last = a.first;
	}
	int ret = 0;
	for(int i:alone){
		ret = max(ret, t-i);
	}
	cout << ret << '\n';
}
