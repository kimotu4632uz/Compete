#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;
    vector<int> a(n-1);
    rep(i,n-1) cin >> a[i];

    sort(all(a));
    int s=0;
    rep(i,n-3) s+=a[i+1];

    if (x-s <= a.front()) cout << 0;
    else if (x-s <= a.back()) cout << x-s;
    else cout << -1;

    return 0;
}