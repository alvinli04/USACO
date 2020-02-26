#include <bits/stdc++.h>
using namespace std;

long long N,K,M;

int milk_after_day(int n, int N, int x){
	int res = 0;
	for(int i = 1; i <=n; i++){
		res += i * pow(x, i-1);
	}
	res *= (N/pow(x,n));
	return res;
}

int main(){
	ifstream in("loan.in");
	in>>N>>K>>M;
	in.close();
	
}
