#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int max = *max_element(p.begin()+1, p.end());
    if (p[0] > max) {
        cout << 0;
    } else {
        cout << max - p[0] +1;
    }
    return 0;
}
