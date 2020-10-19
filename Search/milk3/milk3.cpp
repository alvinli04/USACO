/*
ID: ali201
LANG: C++
TASK: milk3
*/

#include <bits/stdc++.h>
using namespace std;

int m[21][21][21], mxa, mxb, mxc;

void find(int a, int b, int c){
	if(!m[a][b][c]){
		m[a][b][c] = true;
		if(a > mxb - b){
			find(a - mxb + b, mxb, c);
		} else {
			find(0, a+b, c);
		}
		
		if(a > mxc - c){
			find(a - mxc + c, b, mxc);
		} else {
			find(0, b, a + c);
		}
		
		if(b > mxc - c){
			find(a, b - mxc + c, mxc);
		} else {
			find(a, 0, b + c);
		}
		
		if(b > mxa - a){
			find(mxa, b - mxa + a, c);
		} else {
			find(a+b, 0, c);
		}
		
		if(c > mxa - a){
			find(mxa, b, c - mxa + a);
		} else {
			find(a+c, b, 0);
		}
		
		if(c > mxb - b){
			find(a, mxb, c - mxb + b);
		} else {
			find(a, c+b, 0);
		}
	}
}

int main(){
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	
	fin >> mxa >> mxb >> mxc;
	for(int i=0; i<21; i++){
		for(int j = 0; j < 21; j++){
			for(int k = 0; k < 21; k++){
				m[i][j][k] = false;
			}
		}
	}
	
	find(0, 0, mxc);
	set<int> possible;
	for(int i=0; i<21; i++){
		for(int j = 0; j < 21; j++){
			if(m[0][i][j]){
				possible.insert(j);
			}
		}
	}
	possible.erase(*possible.rbegin());
	for(auto i : possible){
		fout << i << ' ';
	}
	fout << mxc << '\n';
}
