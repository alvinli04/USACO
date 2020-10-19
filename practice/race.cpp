#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll get_time(ll dist, ll min){
	ll l=0, r=0, time = 0;
	for(int curr =1;;curr++){
		l+=curr;
		++time;
		if(l+r>=dist) return time;
		if(curr >= min){
			r+=curr;
			++time;
			if(l+r>=dist) return time;
		}
	}
}

int main(){
	freopen("race.in", "r", stdin);
	freopen("race.out", "w", stdout);
	ll k;
	int n;
	cin >> k >> n;
	ll arr[n];
	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	for(ll i:arr){
		cout << get_time(k, i) << '\n';
	}
}
