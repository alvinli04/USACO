#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int n, m;

bool inbound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
} 

int main(){
    IOS;
    cin >> n >> m;
    map<pii, vector<pii>> switches;
    while(m--) {
        int x,y,a,b;
        cin >> x >> y >> a >> b;
        switches[make_pair(x - 1,y - 1)].push_back(make_pair(a - 1,b - 1));
    }
	
    bool lit[n][n];
    bool visited[n][n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            lit[i][j] = false;
            visited[i][j] = false;
        }
    }
    lit[0][0] = true;

    set<pii> connecteds;
    connecteds.insert(make_pair(0,0));
    bool found = true;
    while(found) {
        found = false;
        for(auto itr = connecteds.begin(); itr != connecteds.end(); itr++) {
        	auto coord = *itr;
            visited[coord.first][coord.second] = true;
            for(pii connect_room: switches[coord]) {
                lit[connect_room.first][connect_room.second] = true;
            }
            
            pii cardinals[] = {make_pair(coord.first - 1, coord.second), make_pair(coord.first + 1, coord.second), make_pair(coord.first, coord.second - 1), make_pair(coord.first, coord.second + 1)};
            
            for(pii cardinal : cardinals) {
                if(inbound(cardinal.first, cardinal.second) && lit[cardinal.first][cardinal.second] && !visited[cardinal.first][cardinal.second]) {
                    connecteds.insert(make_pair(cardinal.first, cardinal.second));
                    //for(auto i : connecteds) cout << i.first << i.second << " " << endl;
                    found = true;
                }
            }
        }
        
    }

    int count = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(lit[i][j]) ++count;
        }
    }
    cout << count << "\n";

}
