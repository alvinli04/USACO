/*
USER: ali201
TASK: sort3
LANG: C++
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream fin("sort3.in");
	ofstream fout("sort3.out");
	int n; fin >> n;
	map<int,int> freq;
	int arr[n];
	for(int i=0; i<n; i++){
		fin >> arr[i];
		freq[arr[i]]++;
	}
	multiset<int> ones(arr, arr+(freq[1]));
	multiset<int> twos(arr+(freq[1]), arr+(freq[1] + freq[2]));
	multiset<int> threes(arr+(freq[1] + freq[2]), arr+n);
	//for(int i:threes) cout << i << ' ';
	int moves = 0;
	//12
	while(ones.find(2)!=ones.end() && twos.find(1)!=twos.end()){
		++moves;
		ones.erase(ones.find(2));
		twos.erase(twos.find(1));
	}
	//13
	while(ones.find(3)!=ones.end() && threes.find(1)!=threes.end()){
		++moves;
		ones.erase(ones.find(3));
		threes.erase(threes.find(1));
	}
	//23
	while(twos.find(3)!=twos.end() && threes.find(2)!=threes.end()){
		++moves;
		twos.erase(twos.find(3));
		threes.erase(threes.find(2));
	}
	//final
	for(int i:ones){
		if(i==2){
			moves += 2;
		}
	}
	fout << moves << '\n';
}
