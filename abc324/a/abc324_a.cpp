#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int a; cin >> a;
    bool flag = true;
    for (int i: seq(n-1)) {
        int aa; cin >> aa;
        if (aa != a) flag = false;
    }
    
    if (flag) cout << "Yes";
    else cout << "No";
    return 0;
}