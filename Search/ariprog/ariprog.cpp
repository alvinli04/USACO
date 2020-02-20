/*
ID: ali210
LANG: C++
TASK: ariprog
*/
#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
	ifstream fin("ariprog.in");
	//reads in N, the length of the progressions, and M, the limit. The maximum number in the bisquare set is 2M**2.
	fin >> N >> M;

	fin.close();
	set<int> bisquaresS;
	for(int i = 0; i <= M; i++)
		for(int j = 0; j <= M; j++)
			bisquaresS.insert(i*i + j*j);
	//put all possible bisquares into a set
	map<int, vector<int>> toVal;
	vector<int> bisquares(bisquaresS.begin(), bisquaresS.end());

	bool exist = false;
	bool localexist;
	for(int i = 0; i < bisquares.size(); i++){
		for(int j = i+1; j < bisquares.size(); j++){
			localexist = true;
			int multiplier = bisquares[j] - bisquares[i];
			for(int k = 1; k < N; k++){
				if(find(bisquares.begin(), bisquares.end(), i + multiplier*k) == bisquares.end())
					localexist = false;
					break;
			}
			if(localexist){
				exist = true;
				if(toVal.find(multiplier) != toVal.end())
				{
					toVal.find(multiplier)->second.push_back(i);
					//cout << "hallo";
				}
				else{
					toVal.insert(pair<int, vector<int>>(multiplier, vector<int>{i}));
				}
			}
		}
	}
	//for(auto x : keys) cout<<x<<" ";

	ofstream fout("ariprog.out");
	for(auto i : toVal){
		sort(toVal.find(i)->second.begin(), toVal.find(i)->second.end());
	}
	for(auto i : toVal){
		for(auto const& j : toVal.find(i)->second){
			fout << j << " " << i << "\n";
		}
	}
	if(!exist)
		fout << "NONE\n";
	fout.close();
	return 0;
}
