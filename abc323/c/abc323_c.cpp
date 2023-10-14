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

    auto maxit = max_element(all(scn));
    ll maxs = *maxit;
    int maxi = distance(scn.begin(), maxit);

    
    for (int i: seq(n)) {
        if (i == maxi) {
            cout << 0 << endl;
            continue;
        }

        bool end=false;
        for (int w: seq(1,m+1)) {
            for (int j: seq(m+1-w)) {
                ll now = scn[i];
                for (int k: seq(w)) {
                    if (!solved[i][j+k]) now += sc[j+k];
                }
                if (now > maxs) {
                    cout << w << endl;
                    end = true;
                    break;
                }
            }
            if (end) break;
        }
    }

    return 0;
}