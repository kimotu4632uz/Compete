#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n - 1); i >= 0; --i)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    string s;
    int q;
    vector<tuple<int, int, char>> opr;

    cin >> n >> s >> q;
    rep(i, q) {
        int t, x;
        char q;
        cin >> t >> x >> q;
        opr.push_back({t, x, q});
    }

    auto [lt, lx, lc] = opr.back();
    if (lt == 1) {
        int last_lu = -1;
        irep(i, q) {
            auto [t, x, c] = opr[i];
            if (t != 1) {
                last_lu = i;
                break;
            }
        }

        if (last_lu == -1) {
            rep(i, q) {
                auto [t, x, c] = opr[i];
                s[x - 1] = c;
            }
        } else {
            rep(i, last_lu) {
                auto [t, x, c] = opr[i];
                if (t == 1) {
                    s[x - 1] = c;
                }
            }

            auto [t, x, c] = opr[last_lu];
            if (t == 2) {
                transform(s.begin(), s.end(), s.begin(), ::tolower);
            } else {
                transform(s.begin(), s.end(), s.begin(), ::toupper);
            }

            for (int i = last_lu; i < q; i++) {
                auto [t, x, c] = opr[i];
                if (t == 1) {
                    s[x - 1] = c;
                }
            }
        }

    } else {
        rep(i, q) {
            auto [t, x, c] = opr[i];
            if (t == 1) {
                s[x - 1] = c;
            }
        }
        if (lt == 2) {
            transform(s.begin(), s.end(), s.begin(), ::tolower);
        } else {
            transform(s.begin(), s.end(), s.begin(), ::toupper);
        }
    }

    cout << s << endl;

    return 0;
}