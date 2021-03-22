#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define all(x) (x).begin(),(x).end()

int n, cnt = 0;
int grid[2000][2000];
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};

//check if comf
bool comf(int x, int y){
	int cnt = 0;
	for(int i=0; i<4; i++){
		cnt += (grid[x+dx[i]][y+dy[i]] != 0);
	}
	return cnt == 3;
}
//puts a path of imag cow
void pth(int x, int y){
	if(grid[x][y]) return;
	grid[x][y] = 1;
	++cnt;
	if(comf(x,y)){
		for(int i=0; i<4; i++){
			pth(x+dx[i], y+dy[i]);
		}
	}
	for(int i=0; i<4; i++){
		if(grid[x+dx[i]][y+dy[i]] && comf(x+dx[i], y+dy[i])){
			for(int j=0; j<4; j++)
				pth(x+dx[i]+dx[j], y+dy[i]+dy[j]);
		}
	}
}
//puts a cow
void mk(int x, int y){
	if(grid[x][y] == 1){
		--cnt;
		grid[x][y] = 2;
		return;
	} else{
		grid[x][y] = 2;
		//check self
		if(comf(x,y)){
			for(int i=0; i<4; i++)
				pth(x+dx[i], y+dy[i]);
		}
		//check nbrs
		for(int i=0; i<4; i++){
			if(grid[x+dx[i]][y+dy[i]] && comf(x+dx[i], y+dy[i])){
				for(int j=0; j<4; j++)
					pth(x+dx[i]+dx[j], y+dy[i]+dy[j]);
			}
		}
			
	}
}

int main(){
	cin >> n;
	
	for(int i=0; i<n; i++){
		int a,b; cin >> a >> b;
		a+=450, b+=450;
		mk(a,b);
		cout << cnt << '\n';
	}
	//pg();
}
