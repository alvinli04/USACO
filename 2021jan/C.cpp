#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	int arr[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> arr[i][j];
	int rsum = 0;
	int csum = 0;

	for(int i=0; i<n; i++){
		int crowe = 0;
		int crowo = 0;
		int ccole = 0;
		int ccolo = 0;
		for(int j=0; j<n; j++){
			if(j%2){
				ccolo += arr[j][i];
				crowo += arr[i][j];
			} else {
				crowe += arr[i][j];
				ccole += arr[j][i];
			}
		}
		rsum += max(crowo, crowe);
		csum += max(ccole, ccolo);
	}

	cout << max(rsum, csum);
}
