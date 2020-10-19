/*
TASK: sprime
USER: ali201
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

set<int> p;

int tpow(int n){
	int ans = 1;
	while(n--){
		ans *= 10;
	}
	return ans;
}

bool isprime(int n){
	while(n){
		for(int i=2; i<=(int)sqrt(n); i++){
			if(n % i == 0) return false;
		}
		n/=10;
	}
	return true;
}

void search(int n, int prev){
	if(n == 0){
		if(isprime(prev+1)) p.insert(prev+1);
		if(isprime(prev+3)) p.insert(prev+3);
		if(isprime(prev+7)) p.insert(prev+7);
		if(isprime(prev+9)) p.insert(prev+9);
		return;
	}	
	search(n-1, prev + tpow(n));
	search(n-1, prev + 3*tpow(n));
	search(n-1, prev + 7*tpow(n));
	search(n-1, prev + 9*tpow(n));	
}

int main(){
	ifstream fin("sprime.in");
	ofstream fout("sprime.out");
	int n; fin >> n;
	search(n-2, 2*tpow(n-1));
	search(n-2, 3*tpow(n-1));
	search(n-2, 5*tpow(n-1));
	search(n-2, 7*tpow(n-1));
	for(int i:p){
		fout << i << '\n';
	}
}
