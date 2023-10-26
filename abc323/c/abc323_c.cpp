#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr auto seq(int begin, int end) { return ranges::iota_view(begin, end); }
constexpr auto seq(int end) { return ranges::iota_view(0, end); }
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> sc(m);
    for (int& s: sc) cin >> s;
    
    vector solved(n, vector<bool>(m));
    vector<ll> scn(n);

    for (int i: seq(n)) {
        string s; cin >> s;
        ll score = i+1;

        for (int j: seq(m)) {
            if (s[j] == 'o') {
                score += sc[j];
                solved[i][j] = true;
            } else solved[i][j] = false;
        }
        scn[i] = score;
    }
    
    vector<int> max_idx(m);
    iota(all(max_idx), 0);
    ranges::sort(max_idx, [&sc](int a, int b) {return sc[a] > sc[b];});

    auto maxit = ranges::max_element(scn);
    ll maxs = *maxit;
    int maxi = distance(scn.begin(), maxit);

    
    for (int i: seq(n)) {
        if (i == maxi) {
            cout << 0 << endl;
            continue;
        }

        ll now = scn[i];
        int count = 0;
        for (int j: seq(m)) {
            if (!solved[i][max_idx[j]]) {
                now += sc[max_idx[j]];
                ++count;
                if (now > maxs) {
                    cout << count << endl;
                    break;
                }
            }
        }
    }

    return 0;
}