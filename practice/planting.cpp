#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define pb push_back

void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

int main(){
	setIO("planting");
	
	int n; cin >> n;
	int g[n+1];
	memset(g, 0, sizeof(g));
	for(int i=0; i<n-1; i++){
		int a,b; cin >> a >> b;
		++g[a];
		++g[b];
	}
	
	int mx = 0;
	for(int i=1; i<=n; i++){
		mx = max(mx, g[i]+1);
	}
	
	cout << mx;
}
