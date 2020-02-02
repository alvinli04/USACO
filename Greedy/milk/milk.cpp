/*
ID: ali201
LANG: C++
TASK: milk
 */

#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int N; //milk needed
int M; //amt of farmers

int main()
{
	freopen("milk.in", "r", stdin);
	//freopen("milk.out", "w", stdout);
	map<int, int> prices;
	cin >> N >> M;
	vector<int> ppus;	
	int ppu;
	int u;
	for(int i = 0; i < M; i++)
	{
		cin >> ppu >> u;
		cout << ppu << u;
		prices.insert(pair<int, int>(ppu, u));
		ppus[i] = ppu;
	}
	sort(ppus.begin(), ppus.begin()+M);
	int totalC = 0; //cost
	int totalM = 0; //milk
	for(int i = 0; i < ppus.size(); i++)
	{
		if(totalM + prices.at(ppus[i]) > N)
		{
			totalC += (N - totalM) * i;
			break;
		}
		totalC += i * prices.at(ppus[i]);
		totalM += prices.at(ppus[i]);
	}
	cout << totalC << "\n";
}
