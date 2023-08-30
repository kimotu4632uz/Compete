#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n, h, x;
  vector<int> p;

  cin >> n >> h >> x;
  p.resize(n);
  rep(i, n) cin >> p[i];

  int d = x - h;
  rep(i, n) {
    if (p[i] >= d) {
      cout << i+1 << endl;
      break;
    }
  }

  return 0;
}