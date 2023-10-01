#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto iv(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto iv(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int fromN(vector<int> from, int base) {
    long long sum = 0;
    for (int n : from) {
        sum = sum * base + n;
    }
    return sum;
}

vector<int> toN(int dec, int base, int pad=0) {
    vector<int> result;
    do {
        int num = dec % base;
        result.push_back(num);
        dec /= base;
    } while (dec);
    if (pad != 0) result.resize(pad, 0);
    reverse(result.begin(), result.end());
    return result;
}

long long pow(int x, int y) {
    int res = 1;
    for (int i=0;i<y;++i) res *= x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, p; cin >> n >> k >> p;
    vector<int> c(n);
    vector a(n, vector<int>(k, 0));

    for (int i: iv(n)) {
        cin >> c[i];
        for(int j: iv(k)) cin >> a[i][j];
    }

    const ll inf = 1e12;
    const int stmax = fromN(vector(k,p), p+1) + 1;
    vector dp(n+1, vector<ll>(stmax, inf));
    dp[0][0] = 0;

    for(int i: iv(n)) {
        // iについて何もしなかった場合
        for(int j: iv(stmax)) dp[i+1][j] = dp[i][j];

        for(int j: iv(stmax)) {
            auto st = toN(j, p+1, k);
            for (int x: iv(st.size())) {
                st[x] += a[i][x];
                st[x] = min(st[x], p);
            }
            int stn = fromN(st, p+1);
            if (j != stn) dp[i+1][stn] = min(dp[i][j]+c[i], dp[i+1][stn]);
        }
    }

    ll ans = dp.back().back();
    if (ans == inf) cout << -1;
    else cout << ans;

    return 0;
}