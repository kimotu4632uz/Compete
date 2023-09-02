#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define irep(i, n) for (int i = (n-1); i >= 0; --i)
#define all(v) v.begin(), v.end()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    set<char> ex = {'a','e','i','o','u'};
    string ans;
    for (auto ss : s) {
        if (!ex.contains(ss)) ans += ss;
    }

    cout << ans;
    return 0;
}