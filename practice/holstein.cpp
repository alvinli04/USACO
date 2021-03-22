/*
TASK: holstein
ID: ali201
LANG: C++
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	//freopen("holstein.in", "r", stdin);
	//freopen("holstein.out", "w", stdout);
	
	int v; cin >> v;
	int vit[v]; for(int& a : vit) cin >> a;	
	int g; cin >> g;
	int amt[g][v];
	for(int i=0; i<g; i++)
		for(int j=0; j<v; j++)
			cin >> amt[i][j];
	
}
