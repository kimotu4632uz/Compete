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
    string s; cin >> s;

    if (n == 1) {
        cout << 1;
        return 0;
    }

    vector<int> num(26, 0);
    int count = 1;
    for (int i: seq(n-1)) {
        if (s[i] == s[i+1]) {
            ++count;
        } else {
            num[s[i] - 'a'] = max(num[s[i] - 'a'], count);
            count = 1;
        }
    }
    num[s[n-1] - 'a'] = max(num[s[n-1] - 'a'], count);

    cout << reduce(all(num));
    return 0;
}