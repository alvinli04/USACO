#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back

int n,k;
map<int,int> endpt;
int num;
int vis[100005];
map<int, set<int>> cmp_st;
vector<set<int>> paths(100005);

void dfs(int x){
	if(vis[x]) return;
	vis[x] = num;
	for(int i : paths[x])
		cmp_st[num].insert(i);
	dfs(endpt[x]);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> k;
	
	
	int arr[n+1];
	for(int i=1; i<=n; i++)
		arr[i] = i;
	for(int i=0; i<k; i++){
		int a,b; cin >> a >> b;
		paths[arr[a]].insert(b);
		paths[arr[b]].insert(a);
		swap(arr[a], arr[b]);
	}
	
	for(int i=1; i<=n; i++)
		endpt[arr[i]] = i;
		
	//if in same connected component, then has same size: union of their visiteds
	//also has to be a loop
	
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			++num;
			dfs(i);
		}
	}
	for(int i=1; i<=n; i++){
		cout << max(1, (int)cmp_st[vis[i]].size()) << '\n';
	}
	
}
