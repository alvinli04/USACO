#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,t; cin >> n >> t;
	vector<int> psums(n+1);
	psums[0] = 0;
	for(int i=1; i<=n; i++){
		int x; cin >> x;
		psums[i] = psums[i-1] + x;
	} 
	//for(int i : psums) cout << i << ' '; cout << '\n';
	int mx = 0;
	for(auto i=psums.begin(); i!=psums.end(); i++){
		auto j = lower_bound(psums.begin(), psums.end(), *i + t);
		if(*j != *i+t) --j;
		mx = max(mx, (int)(j - psums.begin()) - (int)(i - psums.begin()));
	}
	cout << mx;
}
