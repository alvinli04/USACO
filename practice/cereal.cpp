#include <bits/stdc++.h>
using namespace std;

int fav[n][2], occ[100001] = {};

void update(int f, int s){
	if()
}

int main(){
	int n,m; cin >> n >> m; //cereals 1-m
	for(int i=0; i<n; i++){
		cin >> fav[i][0] >> fav[i][1];
	}
	map<int,int> taken;
	int output[n+1] = {};
	for(int i=n-1; i>=0; i--){
		if(taken[fav[i][0]] == 0){
			taken[fav[i][0]] = i;
			output[i] = output[i+1]+1;
		} else {
			
		}
	}
}
