#include <bits/stdc++.h>
using namespace std;
 
int main() {
  freopen("homework.in", "r", stdin);
  freopen("homework.out", "w", stdout);
 
  int n; cin >> n;
  
  long long score[n];
  long long ssums[n];
  long long smin[n];
  long long mx, tmx;

  for (int i=1; i<=n; i++) 
    cin >> score[i];
  
  ssums[n] = score[n];
  smin[n] = score[n];
  for (int i=n-1; i>=1; i--) {
    ssums[i] = ssums[i+1] + score[i];
    smin[i] = min(smin[i+1], score[i]);
  }
  mx = 0, tmx = 1;
  
  for (int i=1; i<=n-2; i++) 
    if ((ssums[i+1] - smin[i+1]) * tmx > mx * (n-i-1)) {
      mx = ssums[i+1]-smin[i+1];
      tmx = n-i-1;
    }
  
  for (int i=1; i<=n-2; i++) 
    if ((ssums[i+1] - smin[i+1]) * tmx == mx * (n-i-1)) 
      cout << i << '\n';
}
