#include <bits/stdc++.h>
using namespace std;

vector<int> swap(vector<int> arr, int a, int b){
	int n = arr.size();
	vector<int> ans(n);
	int sz = b-a+1;
	for(int i=0; i<n; i++){
		if(i<a || i>b){
			ans[i] = arr[i];
		}
		else{
			ans[i] = arr[a+sz-(i-a)-1];
		}
	}
	return ans;
}

vector<int> op(vector<int> &a, vector<int> &b){
	int n = a.size();
	vector<int> ans(n);
	for(int i=0; i<n; i++){
		ans[i] = a[b[i]];
	}
	return ans;
}

vector<int> exp(vector<int> a, int pow){
	int n = a.size();
	vector<int> ans(n);
	for(int i=0; i<n; i++){
		ans[i] = i;
	}
	while(pow){
		if(pow%2){
			ans = op(ans, a);
		}
		a = op(a,a);
		pow /= 2;
	}
	return ans;
}

int main(){
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
	
	int n,m,k; cin >> n >> m >> k;
	vector<int> a(n);
	for(int i=0; i<n; i++){
		a[i] = i;
	}
	while(m--){
		int l,r;
		cin >> l >> r;
		--l, --r;
		a = swap(a, l, r);	
	}
	a = exp(a, k);
	for(int i:a){
		cout << i+1 << '\n'; 
	}
}
