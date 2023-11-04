#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

long long pow(int x, int y) {
    long long res = 1;
    for (int i=0;i<y;++i) res *= x;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll b; cin >> b;
    for (int i=1; i<17; ++i) {
        ll p = pow(i, i);
        if (p == b) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}