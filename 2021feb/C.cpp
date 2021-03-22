#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define all(x) (x).begin(),(x).end()

int n;
int hundredo[510][510]; //keeps track of where the 100s are
int baddd[510][510]; //under 100s
int grid[510][510];

int query(int psums[510][510], int uy, int dy, int lx, int rx){
	return psums[dy][rx] + psums[uy-1][lx-1] - psums[dy][lx-1] - psums[uy-1][rx];
}

int main(){
	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> grid[i+1][j+1];
	
	for(int i=1; i<n+1; i++){
		for(int j=1; j<n+1; j++){
			hundredo[i][j] = hundredo[i-1][j] + hundredo[i][j-1] - hundredo[i-1][j-1] + (grid[i][j]==100);
			baddd[i][j] = baddd[i-1][j] + baddd[i][j-1] - baddd[i-1][j-1] + (grid[i][j]<100);
		}
	}

	ll ans = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=i; k++){
				for(int l=1; l<=j; l++){
					if(query(hundredo,k,i,l,j) && !query(baddd,k,i,l,j)){
						//printf("%d %d %d %d\n", k,i,l,j);
						++ans;
					}
				}
			}
		}
	}
	cout << ans;
}

//gets first 5 test cases
