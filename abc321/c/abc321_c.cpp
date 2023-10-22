#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<ll> all321(1022);
    for (int i: seq(2, 1024)) {
        string s;
        for (int j: seq(10)) {
            int flag = (i >> j) & 1;
            if (flag == 1) {
                s.push_back(j + '0');
            }
        }
        ranges::sort(s, greater<char>{});
        all321[i-2] = stoll(s);
    }
    ranges::sort(all321);

    int k; cin >> k;
    cout << all321[k-1];

    return 0;
}