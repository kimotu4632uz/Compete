#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,p;
    cin >> n >> m >> p;
    vector<int> a(n), b(m);
    rep(i,n) cin >> a[i];
    rep(i,m) cin >> b[i];

    sort(all(a)); sort(all(b));
    ll ans=0;
    rep(i,n) {
        if (a[i] >= p) {
            ans += p*(n-i)*m;
            break;
        }
        int r = p-a[i];
        rep(j,m) {
            if (b[j] >= r) {
                ans += p*(m-j);
                break;
            } else {
                ans += a[i]+b[j];
            }
        }
    }

    cout << ans;
    return 0;
}