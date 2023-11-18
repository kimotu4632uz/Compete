#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector<pair<int,int>> lr(q);
    for (int i: seq(q)) {
        int l,r; cin >> l >> r;
        lr[i] = {l-1,r-1};
    }

    vector<int> acc(n);
    acc[0] = 0;
    for (int i: seq(1,n)) {
        if (s[i] == s[i-1]) acc[i] = acc[i-1] + 1;
        else acc[i] = acc[i-1];
    }
    ll result = 0;
    for (auto [l,r]: lr) {
        cout << acc[r] - acc[l] << endl;
    }
    return 0;
}