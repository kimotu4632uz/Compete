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
    string s; cin >> s;

    rep(i,n-2) {
        if (s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C') {
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
    return 0;
}