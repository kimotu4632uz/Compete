#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    ll s = 0; rep(i, n) s += a[i];
    int p = s % n; int ave = s / n;

    sort(all(a));

    ll ans = 0;
    rep(i, n) {
        int c = ave;
        if (i > n-1-p) ++c;
        if (c - a[i] > 0) ans += c-a[i];
    }

    cout << ans;

    return 0;
}
