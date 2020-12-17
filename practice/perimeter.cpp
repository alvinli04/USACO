#include <bits/stdc++.h>
using namespace std;

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

int n;

bool inbounds(int i, int j){
	return 0 <= i && i < n && 0<=j && j<n;
}

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int main(){
	setIO("perimeter");
	
	cin >> n;
	vector<string> inp(n);
	for(auto& a : inp)
		cin >> a;

	vector<vi> g(n*n);
	
	for(int i=0; i<n*n; i++){
		int j = i/n;
		int k = i%n;
		if(inp[j][k] == '#'){
			//cout << i << '\n';
			for(int rep = 0; rep < 4; rep++){
				if(inbounds(j + dx[rep], k + dy[rep]) && inp[j + dx[rep]][k + dy[rep]] == '#'){
					g[i].pb((j + dx[rep])*n + k + dy[rep]);
					g[(j + dx[rep])*n + k + dy[rep]].pb(i);
					//cout << (j + dx[rep])*n + k + dy[rep] << ' ';
				}
			}
			//cout << '\n';
		}
	}
	/*
	for(int i=0; i<g.size(); i++){
		cout << i << ":\n";
		for(int b : g[i]){
			cout << b << ' ';
		}
		cout << '\n';
	}
	*/
	vi maxes;
	
	bool visited[n*n];
	for(bool& i : visited){
		i = false;
	}
	int mx = 0;
	for(int i=0; i<n*n; i++){
		int sz = 0;
		if(!visited[i] && inp[i/n][i%n] == '#'){
			queue<int> q;
			q.push(i);
			visited[i] = true;
			while(q.size()){
				for(int k : g[q.front()]){
					if(!visited[k] && inp[k/n][k%n] == '#'){
						q.push(k);
						visited[k] = true;
					}
				}
				q.pop();
				++sz;
			}
		}	
		if(sz > mx){
			maxes.clear();
			mx = sz;
		} 
		if(sz >= mx){
			maxes.pb(i);
			//cout << mx;
		}
			
	}
	
	int mn_perim = INT_MAX;
	bool visited2[n*n];
	for(bool& i : visited2){
		i = false;
	}
	
	for(int i : maxes){
		int p = 0;
		queue<int> q;
		q.push(i);
		visited2[i] = true;
		while(q.size()){
			int x = q.front() / n;
			int y = q.front() % n;
			for(int j=0; j<4; j++){
				if((inbounds(x+dx[j],y+dy[j]) && inp[x+dx[j]][y+dy[j]] == '.') || !inbounds(x+dx[j],y+dy[j]))
					++p;
				else if (inbounds(x+dx[j],y+dy[j]) && inp[x+dx[j]][y+dy[j]] == '#' && !visited2[(x+dx[j])*n + y+dy[j]]){
					q.push((x+dx[j])*n + y+dy[j]);
					visited2[(x+dx[j])*n + y+dy[j]] = true;
				}	
			}
			q.pop();
		}
		mn_perim = min(mn_perim, p);
	}
	
	cout << mx << ' ' << mn_perim;
	
}



