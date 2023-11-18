#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin>> n >> x;
    int sum = 0;
    for (int i: seq(n)) {
        int s; cin >> s;
        if (s <= x) sum += s;
    }

    cout << sum;
    return 0;
}