#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector g(n, vector(n, 0LL));

    rep(i,n) {
        for (int j=i+1;j<n;++j) {
            ll d; cin >> d;
            g[i][j]=d; g[j][i]=d;
        }
    }

    vector dp((1 << n), 0LL);
    rep(b,(1 << n) - 1) {
        rep(i,n) if (((b >> i) & 1) == 0) {
            rep(j,n) if (((b >> j) & 1) == 0) {
                ll nb = (1 << i) | (1 << j);
                dp[b | nb] = max(dp[b | nb], dp[b] + g[i][j]);
            }
        }
    }

    cout << dp.back();

    return 0;
}