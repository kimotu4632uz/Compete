#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    bool flag = true;
    for (int i: seq(8)) {
        int j = 2*i+1;
        if (s[j] != '0') flag = false;
    }
    
    if (flag) cout << "Yes";
    else cout << "No";

    return 0;
}