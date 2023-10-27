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
    string t; cin >> t;
    vector<string> ss(n);
    for (auto& s: ss) cin >> s;

    string trev = t;
    ranges::reverse(trev);

    vector<int> pre(n), suf(n);
    for (int i: seq(n)) {
        int pc=0;
        for (int j: seq(ss[i].size())) {
            if (pc == t.size()) {
                break;
            }
            if (ss[i][j] == t[pc]) {
                ++pc;
            }
        }

        ranges::reverse(ss[i]);
        int sc=0;
        for (int j: seq(ss[i].size())) {
            if (sc == t.size()) {
                break;
            }
            if (ss[i][j] == trev[sc]) {
                ++sc;
            }
        }
        pre[i] = pc; suf[i] = sc;
    }
    
    vector<int> sufnum(t.size()+1, 0);
    for (auto& e: suf) {
        for (int i: seq(e+1)) {
            ++sufnum[i];
        }
    }
    
    ll ans = 0;
    for (int i: seq(n)) {
        ans += sufnum[t.size() - pre[i]];
    }
    cout << ans;
    return 0;
}