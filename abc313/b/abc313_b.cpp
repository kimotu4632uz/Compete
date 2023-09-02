#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    set<int> a, b;
    rep(i, m) {
        int ai, bi;
        cin >> ai >> bi;
        a.insert(ai); b.insert(bi);
    }

    vector<int> cand;
    for (int i=1; i<=n; i++) {
        if (b.find(i) == b.end()) cand.push_back(i);
    }

    if (cand.size() > 1) cout << -1;
    else cout << cand[0];

    return 0;
}
