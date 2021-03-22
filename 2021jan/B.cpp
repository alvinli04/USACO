#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define pb push_back

int n,q;
string str;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> q >> str;
	int left[n+2], right[n+2];
	memset(left, 0, sizeof(left));
	memset(right, 0, sizeof(right));
	
	stack<char> st;
	//from left
	for(int i=1; i<=n; i++){
		while(!st.empty() && st.top() > str[i-1])
			st.pop();
		if(st.empty() || st.top() < str[i-1]){
			st.push(str[i-1]);
			left[i] = left[i-1]+1;
		}		
		else
			left[i] = left[i-1];
		
	}	
	
	st = stack<char>();
	
	//from right
	for(int i=n; i>=1; i--){
		while(!st.empty() && st.top() > str[i-1])
			st.pop();
		if(st.empty() || st.top() < str[i-1]){
			st.push(str[i-1]);
			right[i] = right[i+1]+1;
		}
		else
			right[i] = right[i+1];
		
	}
	
	while(q--){
		int lo, hi; cin >> lo >> hi;
		cout << left[lo-1] + right[hi+1] << '\n';
	}
	
}
