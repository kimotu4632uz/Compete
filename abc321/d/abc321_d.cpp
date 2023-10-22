#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, p;
    cin >> n >> m >> p;
    vector<ll> a(n), b(m);
    for (auto& e: a) cin >> e;
    for (auto& e: b) cin >> e;

    ranges::sort(b);
    
    vector<ll> bsum(m);
    bsum[0] = b[0];
    for (int i: seq(1,m)) {
        bsum[i] = bsum[i-1] + b[i];
    }

    ll ans=0;
    for (int i: seq(n)) {
        auto it = ranges::lower_bound(b, p-a[i]);
        int k = m;
        if (it != b.end()) {
            k = distance(b.begin(), it);
        }
        
        if (k == 0) {
            ans += p*m;
        } else {
            ans += (k*a[i] + (m-k)*p + bsum[k-1]);
        }
    }

    cout << ans;
    return 0;
}