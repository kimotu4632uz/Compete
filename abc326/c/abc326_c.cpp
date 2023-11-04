#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n,m; cin >> n >> m;
    vector<ll> a(n);
    for (auto& aa: a) cin >> aa;

    ranges::sort(a);

    int ans = 0;
    for (auto i = a.begin(); i< a.end(); ++i) {
        auto it = ranges::lower_bound(a, (*i)+m);
        if (it != a.end()) {
            int count = distance(i, it);
            ans = max(ans, count);
        } else {
            int count = distance(i, a.end());
            ans = max(ans, count);
        }
    }
    cout << ans;
    return 0;
}