#include <bits/stdc++.h>
using namespace std;

int occ[100001], cnt = 0; //milk to cow number
pair<int,int> arr[100001];

void update(int n, int k){ //args: cow n wants milk k
	if(occ[k] == 0){
		//if no cow, just insert
		occ[k] = n;
		++cnt;
		return;
	} else if(n > occ[k]){
		return;
	} else{
		int swp = occ[k];
		occ[k] = n;
		if(k==arr[swp].first){
			update(swp, arr[swp].second);
		} else{
			return;
		}
	}
}

int main(){
	freopen("cereal.in", "r", stdin);
	freopen("cereal.out", "w", stdout);
	
	int n,m; cin >> n >> m;
	
	for(int i=1; i<=n; i++)
		cin >> arr[i].first >> arr[i].second;
	
	vector<int> cnts;
	
	for(int i=n; i>0; i--){
		update(i, arr[i].first);
		cnts.push_back(cnt);
	}
	
	reverse(cnts.begin(), cnts.end());
	for(int a : cnts){
		printf("%d\n", a);
	}
}
