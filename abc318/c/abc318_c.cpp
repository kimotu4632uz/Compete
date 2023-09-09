#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    ll n, d, p;
    cin >> n >> d >> p;
    vector<ll> f(n+(d-n%d), 0);
    rep(i,n) cin >> f[i];

    ll sum =0;
    sort(all(f), greater<ll>());
    rep(i, (n+d-1)/d) {
        ll s=0;
        rep(j,d) s+=f[i*d+j];
        if (s> p) sum+=p;
        else {
            rep(j,d) sum+=f[i*d+j];
        }
    }

    cout << sum;
    return 0;
}