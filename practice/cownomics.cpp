#include <bits/stdc++.h>
using namespace std;

int n,m;

int dig(char c){
	if(c=='A') return 0;
	else if(c=='C') return 1;
	else if(c=='G') return 2;
	else if(c=='T') return 3;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	freopen("cownomics.in", "r", stdin);
	freopen("cownomics.out", "w", stdout);
	
	cin >> n >> m;
	string spot[n], plain[n];
	for(string& i : spot)
		cin >> i;
	for(string& i : plain)
		cin >> i;

	int ans = 0;
	int s[65];
	
	for(int i=0; i<m; i++){
		for(int j=i+1; j<m; j++){
			for(int k=j+1; k<m; k++){
				bool works = 1;
				memset(s,0,sizeof(s));
				for(string sp : plain)
					s[dig(sp[i])*16 + dig(sp[j])*4 + dig(sp[k])] = 1;
				for(string sp : spot){
					if(s[dig(sp[i])*16 + dig(sp[j])*4 + dig(sp[k])]){
						works = 0;
						break;
					}
					
				}
				if(works) ++ans;
			}
		}
	}
	
	cout << ans;
}
