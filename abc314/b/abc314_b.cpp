#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> a;
  a.resize(n);

  rep(i, n) {
    int c;
    cin >> c;

    vector<int> tmp;
    tmp.resize(c);
    rep(j, c) cin >> tmp[j];
    a[i] = tmp;
  }

  int x;
  cin >> x;

  vector<int> winner;
  int winner_c = 40;

  rep(i, n) {
    int found = 0;
    for (auto&& tmp : a[i]) {
      if (tmp == x) {
        found = 1;
        break;
      }
    }
    if (found == 1) {
      int c = a[i].size();
      if (c < winner_c) {
        winner = {i};
        winner_c = c;
      } else if (c == winner_c) {
        winner.push_back(i);
      }
    }
  }

  sort(winner.begin(), winner.end());
  
  cout << winner.size() << endl;
  rep(i, winner.size()) cout << winner[i] + 1 << ' ';

  return 0;
}