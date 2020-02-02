#include <iostream>
using namespace std;

int M, N;

int main()
{
	freopen("milk.in", "r", stdin);
	cin >> N >> M;
	int ppu;
	int u;
	for(int i = 0; i < M; i++)
	{
		cin >> ppu >> u;
		cout << ppu << " " << u << "\n";
	}
}
