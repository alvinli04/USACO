#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back

vector<vi> g(100005);
bool visited[100005];
ll s = 0;

void dfs(int k){
	visited[k] = 1;
	if(k == 1){
		s += g[k].size() + ceil(log2(g[k].size() + 1));
	}
	else if(g[k].size() > 1)
		s += g[k].size() - 1 + ceil(log2(g[k].size()));
	
	for(int a : g[k])
		if(!visited[a])
			dfs(a);
	
}

int main(){
	int n; cin >> n;
	
	for(int i=0; i<n-1; i++){
		int a,b; cin >> a >> b;
		g[a].pb(b);
		g[b].pb(a);
	}
	
	dfs(1);
	cout << s;
}
