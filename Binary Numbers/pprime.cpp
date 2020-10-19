/*
USER: ali201
TASK: pprime
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool isprime(ll n){
	//check up to sqrt(n)
	for(int i=2; i<=(int)sqrt(n); i++){
		if(n%i == 0) return false;
	}
	return true;
}

int main(){
	ifstream fin("pprime.in");
	ofstream fout("pprime.out");
	ll a,b; fin >> a >> b;
	set<ll> primes;
	for(int i=0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 10; k++){
				for(int l = 0; l < 10; l++){
					ll g = 10000000*i + 1000000*j + 100000*k + 10000*l + 1000*l + 100*k + 10*j + i;
					ll h = 1000000*i + 100000*j + 10000*k + 1000*l + 100*k + 10*j + i;
					if(a <= g && b >= g && isprime(g)) primes.insert(g);
					if(a <= h && b >= h && isprime(h)) primes.insert(h);
				}
			}
		}
	}
	for(int i=0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			for(int k = 0; k < 10; k++){
				ll g = 100000*i + 10000*j + 1000*k + 100*k + 10*j + i;
				ll h = 10000*i + 1000*j + 100*k + 10*j + i;
				if(a <= g && b >= g && isprime(g)) primes.insert(g);
				if(a <= h && b >= h && isprime(h)) primes.insert(h);
			}
		}
	}
	for(int i=0; i<10; i++){
		for(int j=0; j<10; j++){
			ll g = i*1001 + j*110;
			ll h = i*101 + j*10;
			if(a <= g && b >= g && isprime(g)) primes.insert(g);
			if(a <= h && b >= h && isprime(h)) primes.insert(h);
		}
	}
	for(int i=2; i<10; i++){
		if(a <= i && b >= i && isprime(i)) primes.insert(i);
	}
	if(a <= 11 && b >= 11){
		primes.insert(11);
	}
	//cout << primes.size();
	for(auto m : primes){
		fout << m << '\n';
	}
}
