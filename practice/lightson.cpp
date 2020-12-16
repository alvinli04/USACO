#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("lightson.in", "r", stdin);
	freopen("lightson.out", "w", stdout);
	
	int n,m; cin >> n >> m;
	map<pair<int,int>, vector<pair<int,int>>> mp;
	
	while(m--){
		int a,b,c,d; cin >> a >> b >> c >> d;
		mp[{a,b}].push_back({c,d});
	}
	
	set<pair<int,int>> on, visited;
	on.insert({1,1});
	visited.insert({1,1});
	for(auto a : mp[{1,1}]){
		on.insert(a);
	}
	

	while(true){
		bool non = true;
		for(auto a = on.begin(); a != on.end(); a++){
			pair<int,int> pr = *a;
			//for a node that's on but not visited, if one its surrounding nodes is visited then it is also visitable.
			if(visited.find(pr) == visited.end() && 
			(visited.find({pr.first - 1, pr.second}) != visited.end() || 
			 visited.find({pr.first + 1, pr.second}) != visited.end() || 
			 visited.find({pr.first, pr.second - 1}) != visited.end() || 
			 visited.find({pr.first, pr.second + 1}) != visited.end()
			 )
			 ){
				visited.insert(*a);
				//there was a node that was visited
				non = false;
				//flick switches
				for(auto b : mp[*a]){
					on.insert(b);
				}
			}
		}
		//if no new node visited, then we're done
		if(non){
			break;
		}
	}
	
	cout << on.size();
}
