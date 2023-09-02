#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> m(n, vector<int>());
    rep(i, n) {
        int f, s;
        cin >> f >> s;
        --f;
        m[f].push_back(s);
    }

    vector<int> ms;
    rep(i, n) {
        sort(all(m[i]));
        if (!m[i].empty()) {
            ms.push_back(m[i].back());
        }
    }

    sort(all(ms));
    int cand = 0;
    if (ms.size() >= 2) {
        cand = ms.back() + *(ms.end()-2);
    }

    int cand1 = 0;
    rep(i,n) {
        if (!m[i].empty() && m[i].size() >= 2) {
            cand1 = max(cand1, m[i].back() + *(m[i].end()-2)/2);
        }
    }

    cout << max(cand, cand1) << endl;

    return 0;
}