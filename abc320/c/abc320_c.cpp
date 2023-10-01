#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> m;
    vector<string> s(3);
    cin >> s[0] >> s[1] >> s[2];

    vector in(3, vector<bool>(10,false));
    vector idx(10, vector(3, vector<int>()));

    for (int i: seq(3)) {
        for (int j: seq(s[i].size())) {
            int n = s[i][j] - '0';
            in[i][n] = true;
            idx[n][i].push_back(j);
        }
    }

    vector<int> cands;
    for (int i: seq(10)) {
        bool flag = true;
        for (int j: seq(3)) if (!in[j][i]) flag = false;
        if (flag) cands.push_back(i);
    }
    if (cands.empty()) {
        cout << -1;
        return 0;
    }

    int result = 0;
    vector<int> sn(3);
    iota(all(sn), 0);

    for (int c: cands) {
        do {
            int first = idx[c][sn[0]][0];

            int second = 0;
            int base = 0;
            auto seci = lower_bound(all(idx[c][sn[1]]), first+1);
            if (seci != idx[c][sn[1]].end()) second = *seci;
            else {
                second = idx[c][sn[1]][0] + m;
                base = m;
            }

            int last = 0;
            auto lasi = lower_bound(all(idx[c][sn[2]]), second-base+1);
            if (lasi != idx[c][sn[2]].end()) last = *lasi + base;
            else last = idx[c][sn[2]][0] + m + base;

            if (result == 0) result = last;
            else result = min(result, last);
        } while (next_permutation(all(sn)));
    }

    cout << result;
    return 0;
}