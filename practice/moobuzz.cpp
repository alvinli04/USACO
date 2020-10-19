#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
	int64_t n; cin >> n;
	int64_t l=0, r=2*n;
	int64_t ans;
	while(l<=r){
		int64_t m=(l+r)/2;
		if(m - m/3 - m/5 + m/15 >= n){
			ans = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << ans << '\n';
}
