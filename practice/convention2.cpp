#include <bits/stdc++.h>
using namespace std;

struct cmp{
	bool operator()(vector<int> a, vector<int> b){
		return a[2] < b[2];
	}
};

int main(){
	freopen("convention2.in", "r", stdin);
	freopen("convention2.out", "w", stdout);
	
	int n; cin >> n;
	vector<vector<int>> v(n, vector<int>(3));
	for(int i=0; i<n; i++){
		cin >> v[i][0] >> v[i][1]; //arrival, time spent
		v[i][2] = i;
	}
	sort(v.begin(), v.end());
	set<vector<int>, cmp> s;
	int curr_end = 0, ans=0;
	for(auto a:v){
		s.insert(a);
		while(curr_end < a[0]){
			auto itr=s.begin();
			ans=max(ans, curr_end - (*itr)[0]);
			curr_end = (*itr)[1] + max(curr_end, (*itr)[0]);
			s.erase(itr);
		}
	}
	cout << ans << '\n';
}


