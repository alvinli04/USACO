#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	
	int arr[n];
	for(int& i : arr) cin >> i;
	int cnt = 0;
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			int s = 0;
			bool p = 0;
			for(int k=i; k<=j; k++){
				s += arr[k];
			}
			for(int k=i; k<=j; k++){
				if(arr[k] * (j-i+1) == s)
					p = 1;
			}
			cnt += p;
		}
	}
	
	cout << cnt;
}
