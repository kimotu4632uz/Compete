#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<ll,ll>> sc(n);
    for (int i: seq(n)) {
        ll s, c; cin >> s >> c;
        sc[i] = {s,c};
    }

    ranges::sort(sc);
    
    vector<bool> seen(n, false);
    ll ans = 0;
    for (int i: seq(n)) {
        auto [s,c] = sc[i];
        if (seen[i]) continue;

        for (ll j=2; j<1e9; j*=2) {
            auto it = ranges::lower_bound(sc, s*j, {}, &pair<ll,ll>::first);
            if (it != sc.end() && (*it).first == s*j) {
                int idx = distance(sc.begin(), it);
                c += j*(*it).second;
                seen[idx] = true;
            }
        }
        
        while (true) {
            if ((c & 1) == 1) ++ans;
            if (c < 2) break;
            else c >>= 1;
        }
    }

    cout << ans;
    return 0;
}