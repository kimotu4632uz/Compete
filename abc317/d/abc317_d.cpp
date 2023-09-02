#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> w(n), z(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y >> z[i];
        w[i] = max(0,(x+y+1)/2-x);
    }

    int total = accumulate(all(z), 0);

    vector<ll> dp(total+1, 1e18); dp[0] = 0;
    rep(i, n) {
        for (int j=total; j>=z[i]; --j) {
            dp[j] = min(dp[j], dp[j-z[i]]+w[i]);
        }
    }

    cout << *min_element(dp.begin()+((total+1)/2), dp.end());

    return 0;
}