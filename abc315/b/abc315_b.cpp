#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> m;
    vector<int> d(m);
    rep(i, m) cin >> d[i];

    int s=0; rep(i,m) s+=d[i];
    int mid = s/2+1;

    int t = 0;
    rep(i,m) {
        t += d[i];
        if (t >= mid) {
            cout << i+1 << ' ' << d[i] - (t - mid);
            break;
        }
    }

    return 0;
}