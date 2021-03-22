#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define pb push_back
#define all(x) (x).begin(),(x).end()

int n,k;

int main(){
	cin >> n >> k;
	//upper and lower bounds that are mults of 12 matter
	pii bds[n];
	for(int i=0; i<n; i++){
		int b; cin >> b;
		bds[i] = make_pair((b/12) * 12, (b/12+1)*12);
	}
	sort(bds, bds+n);
	int mxc = bds[n-1].second;
	
	//consec diffs
	int diffs[n-1];
	for(int i=1; i<n; i++){
		diffs[i-1] = bds[i].first - bds[i-1].second;
	}
	sort(diffs, diffs+(n-1));
	//casework: jump to get back to present, or wait for present
	//case 1: k-1 groups, 0 not included, k-2 gaps + last-> 0
	int s = 0;
	for(int i=n-2; i>n-k; i--){
		s += (diffs[i] > 0 ? diffs[i] : 0);
	}
	
	//case 2: k groups, 0 included
	int p = 0;
	for(int i=n-2; i>n-k-1; i--)
		p += (diffs[i] > 0 ? diffs[i] : 0);
	
	cout << min(mxc - s - bds[0].first, mxc - p);
}
