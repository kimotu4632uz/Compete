#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  priority_queue<int> q;

  cin >> n;
  rep(i,n) {
    int t;
    cin >> t;
    q.push(t);
  }

  int p = q.top();
  q.pop();
  rep(i,n-1) {
    int t = q.top();
    q.pop();
    if (p - t != 1) {
      cout << p-1 << endl;
      break;
    }
    p = t;
  }
  return 0;
}