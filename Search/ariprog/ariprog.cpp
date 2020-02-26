/*
ID: ali210
LANG: C++
TASK: ariprog
*/
#include <bits/stdc++.h>
using namespace std;

int N, M;
map<int, set<int>> toVal;
//set<int> keys;

int main()
{
	ifstream fin("ariprog.in");
	fin >> N >> M; //length progressions, bound
	int maxBi = 2*M*M;
	vector<bool> bisquares(maxBi + 1);
	for(int i = 0; i <= maxBi; i++){
		for(int j = 0; j <= maxBi; j++){
			bisquares[i*i+j*j] = true;
		}
	}
	fin.close();
	bool exist;
	for(int i = 0; i < maxBi; i++){
		if(!bisquares[i]){
			continue;
		}
		exist = true;
		for(int j = 1;  j <= (maxBi-i)/(N-1); j++){
			for(int k = 1; k < N; k++){
				if(!bisquares[i+j*k]){
					cout << "joe";
					exist = false;
					break;
				}
			}
			if(!exist){
				continue;
			}
			toVal[j].insert(i);
		}
	}

	ofstream fout("ariprog.out");

	for(auto const& x : toVal){
		//cout << x;
	}
	if(toVal.size() == 0){
		fout << "NONE\n";
	}
	fout.close();
	return 0;
}
