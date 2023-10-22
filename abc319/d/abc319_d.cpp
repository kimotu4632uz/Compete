#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<ll> ls(n);
    for (int i: seq(n)) {
        ll t; cin >> t;
        ls[i] = t+1;
    }
    
    ll lower = ranges::max(ls);
    ll upper = reduce(all(ls));

    auto it = ranges::partition_point(views::iota(lower, upper), [&](ll w) {
        ll colnum = 1;
        ll sum = 0;
        for (auto&& e: ls) {
            if (sum + e > w) {
                sum = e; ++colnum;
            } else {
                sum += e;
            }
        }
        return colnum > m;
    });
    
    cout << *it - 1;
    return 0;
}