#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("hoofball.in", "r", stdin);
	freopen("hoofball.out", "w", stdout);
	int n; cin >> n;
	int pos[n];
	for(int i=0; i<n; i++){
		cin >> pos[i];
	}
	int ans = 0;
	sort(pos, pos+n);
	int passes[n];
	fill(passes, passes+n, 0);
	bool who[n]; //left 0 right 1
	who[0] = 1, who[n-1] = 0;
	for(int i=1; i<n-1; i++){
		if(pos[i+1] - pos[i] < pos[i] - pos[i-1]) who[i] = 1;
		else who[i] = 0;
	}
	//for(auto i: who) cout << i << ' ';
	for(int i=0; i<n; i++){
		if(who[i]) passes[i+1]++;
		else passes[i-1]++;
	}
	//for(auto i : passes) cout << i << ' ';
	for(int i=1; i<n; i++){
		if(!who[i] && who[i-1] && passes[i]==1 && passes[i-1]==1){
			++ans;
		}
	}
	for(int i: passes){
		if(i==0) ++ans;
	}
	cout << ans << '\n';
}
