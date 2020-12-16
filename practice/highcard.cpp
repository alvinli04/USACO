#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("highcard.in", "r", stdin);
	freopen("highcard.out", "w", stdout);
	
	int n; cin >> n;
	set<int> elsie, bessie;
	
	for(int i=0; i<n; i++){
		int k; cin >> k;
		elsie.insert(k);
	}
	
	for(int i = 1; i <= 2*n; i++){
		if(elsie.find(i) == elsie.end())
			bessie.insert(i);
	}
	int s = 0;
	for(auto itr = elsie.begin(); itr != elsie.end(); itr++){
		auto h = bessie.upper_bound(*itr);
		if(h!=bessie.end()){
			bessie.erase(*h);
			++s;
		}
	}
	cout << s;
}
