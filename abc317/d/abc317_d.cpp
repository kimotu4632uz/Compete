#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> x, y, z;
  x.resize(n); y.resize(n); z.resize(n);
  rep(i,n) {
    cin >> x[i] >> y[i] >> z[i];
  }

  int total = 0;
  rep(i,n) total += z[i];
  int win = (total + 1)/2;

  int have = 0;
  auto c = [](tuple<float,int,int>& l, tuple<float,int,int>& r) {
    auto [lr,lc,lv] = l; auto [rr,rc,rv] = r;
    if (lr == rr) {
      if (lv == rv) {
        return lc > rc;
      } else {
        return lv < rv;
      }
    } else {
      return lr > rr;
    }
  };
  priority_queue<tuple<float,int,int>, vector<tuple<float,int,int>>, decltype(c)> q(c);
  rep(i,n) {
    if (x[i] > y[i]) {
      have += z[i];
    } else {
      int c = (x[i]+y[i]+1)/2-x[i];
      int v = z[i];
      q.push({(float)(c/v), c, v});
    }
  }

  int result = 0;
  if (have >= win) {
    cout << 0 << endl;
  } else {
    rep(_, n) {
      auto [r, c, v] = q.top();
      q.pop();
      have += v;
      result += c;

      if (have >= win) {
        cout << result << endl;
        break;
      }
    }
  }

  return 0;
}