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
    string s, t;
    cin >> s >> t;

    bool pre=true, suf=true;

    rep(i,n) if (s[i] != t[i]) pre=false;
    rep(i,n) if (s[i] != t[m-n+i]) suf=false;

    if (pre && suf) cout << 0;
    else if (pre) cout << 1;
    else if (suf) cout << 2;
    else cout << 3;

    return 0;
}