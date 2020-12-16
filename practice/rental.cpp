#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	
	int64_t n,m,r; cin >> n >> m >> r;
	int64_t milk[n], rent[r];
	pair<int64_t,int64_t> price[m];
	for(auto& a : milk) cin >> a;
	for(auto& a : price){
		cin >> a.second >> a.first; //price, gallons
	}
	for(auto& a : rent) cin >> a;
	sort(rent, rent+r, greater<int64_t>());
	sort(milk, milk+n, greater<int64_t>());
	sort(price, price+m, greater<pair<int64_t,int64_t>>());
	int64_t rent_sum[r+1];
	//cout << r;
	rent_sum[1] = rent[0];
	rent_sum[0] = 0;
	for(int i=2; i<=r; i++){
		rent_sum[i] = rent_sum[i-1] + rent[i-1];
	}
	//rent_sum[x]: rent x cows
	int64_t ans = rent_sum[min(r,n)];
	int64_t cmilk = 0, milkprice = 0;
	int cnt = 0;
	for(int i=0; i<n; i++){
		cmilk=milk[i];
		while(cmilk && cnt<m){
			int64_t mn = min(cmilk, price[cnt].second);
			cmilk-=mn;
			price[cnt].second-=mn;
			milkprice+=mn*(price[cnt].first);
			if(price[cnt].second==0) ++cnt;
		}
		ans=max(ans, rent_sum[min(r, n-i-1)] + milkprice);
		//cout << rent_sum[4] << '\n';
	}
	cout << ans << '\n';
}
