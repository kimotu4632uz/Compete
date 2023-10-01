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

    int ans = 1;
    for(int i: seq(s.size())) {
        for(int j: seq(i+1,s.size())) {
            auto ss = s.substr(i,j-i+1);
            bool flag = true;
            for (int k: seq(ss.size())) {
                if (ss[k] != ss[ss.size()-k-1]) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans = max(ans, (int)ss.size());
        }
    }

    cout << ans;
    return 0;
}