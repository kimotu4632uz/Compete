#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int x, y; cin >> x >> y;
    if (x < y) {
        if (y-x > 2) cout << "No";
        else cout << "Yes";
    } else {
        if (x-y > 3) cout << "No";
        else cout << "Yes";
    }
    return 0;
}