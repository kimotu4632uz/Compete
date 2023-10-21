#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> w(n), x(n);
    for (int i: seq(n)) cin >> w[i] >> x[i];

    int ans = 0;
    for (int i: seq(24)) {
        int sum = 0;
        for (int j: seq(n)) {
            int start = i + x[j];
            if (start > 23) start -= 24;
            if (start >= 9 && start <= 17) sum += w[j];
        }
        ans = max(ans, sum);
    }
    
    cout << ans;
    return 0;
}