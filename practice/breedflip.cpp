#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("breedflip.in", "r", stdin);
	freopen("breedflip.out", "w", stdout);
	int n; cin >> n;
	string a,b; cin >> a >> b;
	int ans = 0;
	bool diff = false;
	for(int i=0; i<n; i++){
		if(a[i] == b[i]){
			if(diff) ++ans;
			diff = false;
		} else {
			diff = true;
		}
	}
	
	cout << ans << '\n';
}
