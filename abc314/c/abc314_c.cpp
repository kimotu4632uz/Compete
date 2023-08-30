#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  string s;
  vector<int> c;

  cin >> n >> m >> s;
  c.resize(n);
  rep(i, n) cin >> c[i];

  vector<vector<int>> map;
  map.resize(m);

  rep(i, n) map[c[i]-1].push_back(i);

  rep(i, m) {
    auto last = s[map[i].back()];
    for (int j=map[i].size()-1; j>0; j--) {
      s[map[i][j]] = s[map[i][j-1]];
    }
    s[map[i][0]] = last;
  }

  cout << s << endl;
  return 0;
}