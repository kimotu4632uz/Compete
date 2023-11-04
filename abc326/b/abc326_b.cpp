#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) std::ranges::begin((v)), std::ranges::end((v))

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i: seq(n, 920)) {
        string s = to_string(i);
        if ((s[0]-'0') * (s[1]-'0') == (s[2]-'0')) {
            cout << s;
            break;
        }
    }
    return 0;
}