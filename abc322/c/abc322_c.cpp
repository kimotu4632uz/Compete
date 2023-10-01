#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int& aa : a) cin >> aa;

    int j=0;
    for (int i=1;i<=n;++i) {
        cout << a[j]-i << endl;
        if (a[j] == i) ++j;
    }
    return 0;
}