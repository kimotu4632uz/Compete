#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> graph(n, vector<int>(n, 0));
  rep(i, m) {
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    graph[a][b] = c;
    graph[b][a] = c;
  }
  
  vector<int> p(n);
  iota(all(p), 0);
  int ans = 0;
  do {
    int sum = 0;
    rep(i, n-1) {
      int c = graph[p[i]][p[i+1]];
      if (c == 0) break;
      else sum += c;
    }
    ans = max(ans, sum);
  } while(next_permutation(all(p)));

  cout << ans;
  return 0;
}